# MySQL

记录 *MySQL* 的一些东西，如注意事项、使用技巧等等。

**参考书籍**

- 《*MySQL* 必知必会》

---

   * [MySQL](#mysql)
      * [<em>Primary key</em>（主键）的最好习惯](#primary-key主键的最好习惯)
      * [数据的默认检索顺序](#数据的默认检索顺序)
      * [应用层（如 <em>Java</em>、<em>Python</em> 等）过滤的缺点](#应用层如-javapython-等过滤的缺点)
      * [执行匹配时的默认规则](#执行匹配时的默认规则)
      * [NULL 与 不匹配](#null-与-不匹配)
      * [IN 操作符的优势](#in-操作符的优势)
      * [通配符的使用技巧](#通配符的使用技巧)
      * [对非数值数据使用 MAX()](#对非数值数据使用-max)
      * [对非数值数据使用 MIN()](#对非数值数据使用-min)
      * [使用 ROLLUP](#使用-rollup)

## *Primary key*（主键）的最好习惯

- 不更新主键列中的值
- 不重用主键列的值
- 不在主键列中使用可能会更改的值（如：企业或个人的姓名、电话等）

---

## 数据的默认检索顺序

***MySQL* 检索出的数据并不是以纯粹的随机顺序显示**，而是将以它在底层中表现出来的顺序显示（比如添加到表中的顺序）。但是如果后来进行了更新或删除操作，那么此顺序将会收到影响。

因此，如果不明确控制的话，不能依赖该排序顺序。关系数据库设计理论认为，**如果不明确排序顺序，则不应该假定检索出的数据的顺序有意义**。

---

## 应用层（如 *Java*、*Python* 等）过滤的缺点

- 极大的影响应用的性能
- 不具备可伸缩性
- 网络带宽浪费

> 应用层过滤是指不使用 *MySQL* 自身的过滤机制（如 `WHERE`、`LIKE` 等），而是靠自身的条件判断对数据进行**二次过滤**的行为。

---

## 执行匹配时的默认规则

*MySQL* 在执行匹配时默认不区分大小写（即 `fuses` 会匹配到 `fuses` 和 `Fuses`），所以在区分大小写的项目中要格外注意这一点。

``` sql
/*
    有这样一个表 products
    +--------------+------------+
    | prod_name    | prod_price |
    +--------------+------------+
    | Carrots      |       2.50 |
    | Fuses        |       3.42 |
    | JetPack 1000 |      35.00 |
    | JetPack 2000 |      55.00 |
    | Oil can      |       8.99 |
    +--------------+------------+
*/

/* 执行操作 */
SELECT prod_name, prod_price FROM products WHERE prod_name = 'fuses';

/*
    结果如下
    +-----------+------------+
    | prod_name | prod_price |
    +-----------+------------+
    | Fuses     |       3.42 |
    +-----------+------------+
    结果的 Fuses 与 fuses 不完全匹配，所以证明 MySQL 默认匹配是不区分大小写的
*/
```

---

## `NULL` 与 不匹配

*MySQL* 中 `NULL` 具有特殊含义，所以数据库在匹配过滤（即 `=` 或 `!=` 等操作）时不知道与 `NULL` 是否匹配，所以结果不返回具有 `NULL` 值的行。

适用于这个规则的**操作符**：

- `WHERE`
- `LIKE`
- `AVG()`
- `COUNT(column)` 同时也会忽略空值
- `MAX()`
- `MIN()`
- `SUM()`

``` sql
/*
    有这样一个表 customers
    +----------------+---------------------+
    | cust_name      | cust_email          |
    +----------------+---------------------+
    | Coyote Inc.    | ylee@coyote.com     |
    | Mouse House    | NULL                |
    | Wascals        | rabbit@wascally.com |
    | Yosemite Place | sam@yosemite.com    |
    | E Fudd         | NULL                |
    +----------------+---------------------+
*/

/* 执行操作 */
SELECT cust_name, cust_email FROM customers WHERE cust_email <> 'Lucy@lucy.com';

/*
    结果如下
    +----------------+---------------------+
    | cust_name      | cust_email          |
    +----------------+---------------------+
    | Coyote Inc.    | ylee@coyote.com     |
    | Wascals        | rabbit@wascally.com |
    | Yosemite Place | sam@yosemite.com    |
    +----------------+---------------------+
    结果中并没有带 Mouse House 和 E Fudd 用户的行，说明 NULL 值并没有参与过滤
*/
```

---

## `IN` 操作符的优势

`IN` 操作符与 `OR` 操作符完成同样的功能，但是它还有别的**优势**：

- 在使用长的合法选项清单时，`IN` 操作符的语法更清楚且更直观
- 在使用 `IN` 时，计算的次序更容易管理（因为使用的操作符更少）
- `IN` 操作符一般比 `OR` 操作符清单执行更快
- `IN` 的最大有点是可以包含其他 `SECECT` 语句，是能够更好更动态地建立 `WHERE` 子句

---

## 通配符的使用技巧

- 不要过度使用通配符。如果其他操作符能达到相同的目的，应该使用其他操作符
- 在确实需要使用通配符时，除非绝对有必要，否则不要把他们用在搜索模式的开始处。把通配符置于搜索模式的开始处，搜索起来是最慢的
- 仔细注意通配符的位置。如果放错位置，可能不会返回想要的数据

---

## 对非数值数据使用 `MAX()`

*MySQL* 允许将 `MAX()` 用来返回任意列中的最大值，包括返回文本列中的最大值。

在用于文本数据时，如果数据按相应的列排序，则 `MAX()` 返回最后一行。

``` sql
/*
    有这样一个表 products
    +----------------+------------+
    | prod_name      | prod_price |
    +----------------+------------+
    | .5 ton anvil   |       5.99 |
    | 1 ton anvil    |       9.99 |
    | 2 ton anvil    |      14.99 |
    | Detonator      |      13.00 |
    | Bird seed      |      10.00 |
    | Carrots        |       2.50 |
    | Fuses          |       3.42 |
    | JetPack 1000   |      35.00 |
    | JetPack 2000   |      55.00 |
    | Oil can        |       8.99 |
    | Safe           |      50.00 |
    | Sling          |       4.49 |
    | TNT (1 stick)  |       2.50 |
    | TNT (5 sticks) |      10.00 |
    +----------------+------------+
*/

/* 执行操作 */
SELECT MAX(prod_name) FROM products;

/*
    结果如下
    +----------------+
    | max(prod_name) |
    +----------------+
    | TNT (5 sticks) |
    +----------------+
    结果中使用 MAX() 对文本列进行汇总，其结果是排序的最后一行
*/
```

---

## 对非数值数据使用 `MIN()`

*MySQL* 允许将 `MIN()` 用来返回任意列中的最小值，包括返回文本列中的最小值。

在用于文本数据时，如果数据按相应的列排序，则 `MIN()` 返回最前面的行（即首行）。

``` sql
/*
    有这样一个表 products
    +----------------+------------+
    | prod_name      | prod_price |
    +----------------+------------+
    | .5 ton anvil   |       5.99 |
    | 1 ton anvil    |       9.99 |
    | 2 ton anvil    |      14.99 |
    | Detonator      |      13.00 |
    | Bird seed      |      10.00 |
    | Carrots        |       2.50 |
    | Fuses          |       3.42 |
    | JetPack 1000   |      35.00 |
    | JetPack 2000   |      55.00 |
    | Oil can        |       8.99 |
    | Safe           |      50.00 |
    | Sling          |       4.49 |
    | TNT (1 stick)  |       2.50 |
    | TNT (5 sticks) |      10.00 |
    +----------------+------------+
*/

/* 执行操作 */
SELECT MIN(prod_name) FROM products;

/*
    结果如下
    +----------------+
    | min(prod_name) |
    +----------------+
    | .5 ton anvil   |
    +----------------+
    结果中使用 MIN() 对文本列进行汇总，其结果是排序的第一行
*/
```

---

## 使用 `ROLLUP`

*MySQL* 中将数据进行分组后，如果想在结果最后进行一波汇总的话，可以考虑 `WITH ROLLUP` 关键字。

``` sql
/*
	有这样一个表 products
    +---------+----------------+
    | vend_id | prod_name      |
    +---------+----------------+
    |    1001 | .5 ton anvil   |
    |    1001 | 1 ton anvil    |
    |    1001 | 2 ton anvil    |
    |    1003 | Detonator      |
    |    1003 | Bird seed      |
    |    1003 | Carrots        |
    |    1002 | Fuses          |
    |    1005 | JetPack 1000   |
    |    1005 | JetPack 2000   |
    |    1002 | Oil can        |
    |    1003 | Safe           |
    |    1003 | Sling          |
    |    1003 | TNT (1 stick)  |
    |    1003 | TNT (5 sticks) |
    +---------+----------------+
*/

/* 执行操作 */
SELECT vend_id, COUNT(*) AS num_prods FROM products GROUP BY vend_id;

/*
	结果如下
    +---------+-----------+
    | vend_id | num_prods |
    +---------+-----------+
    |    1001 |         3 |
    |    1002 |         2 |
    |    1003 |         7 |
    |    1005 |         2 |
    +---------+-----------+
*/

/* 执行操作 */
SELECT vend_id, COUNT(*) AS num_prods FROM products GROUP BY vend_id WITH ROLLUP;

/*
	结果如下
    +---------+-----------+
    | vend_id | num_prods |
    +---------+-----------+
    |    1001 |         3 |
    |    1002 |         2 |
    |    1003 |         7 |
    |    1005 |         2 |
    |    NULL |        14 |
    +---------+-----------+
    可以看到，检索结果的最后一行有一个分组数据汇总
*/
```

