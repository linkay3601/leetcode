# Awk Powerful Language

Document the use of the __Awk__.

## Awk Syntax

Basic Awk Syntax.

``` bash
awk -Fs '/pattern/ {action}' input-file
(or)
awk -Fs '{action}' intput-file
```

## Program Structure

Syntax of BEGIN block.

``` bash
BEGIN { awk-commands }
```

Syntax of body block.

``` bash
/pattern/ {action}
```

Syntax of END block.

``` bash
END { awk-commands }
```

## Built-in Variables

Built-in variables and their descriptions.

| Variable | Describe |
| :------: | :------: |
| FS | 输入字段分离器 |
| OFS | 输出字段分离器 |
| RS | 输入记录分离器 |
| ORS | 输出记录分离器 |
| NR | 记录数量 |
| FILENAME | 当前文件名称 |
| FNR | 文件记录数量 |
| SUBSEP | 自定义 Subscript Separator |

## Variables and Operators

There are no data types in Awk.

Whether an awk variable is a number or a string depends on the context in which the variable is used in.

### Operators for Awk

| Operator  | Describe |
| :------:  | :------: |
| +         | 正       |
| -         | 负       |
| ++        | 自增     |
| --        | 自减     |
| +         | 加       |
| -         | 减       |
| *         | 乘       |
| /         | 除       |
| %         | 取余     |
| \<Space\> | 连接符   |
| =         | 赋值     |
| +=        | 加赋值   |
| -=        | 减赋值   |
| \*=       | 乘赋值   |
| /=        | 除赋值   |
| %=        | 取余赋值 |
| >         | 大于     |
| >=        | 大于等于 |
| <         | 小于     |
| <=        | 小于等于 |
| ==        | 恒等于   |
| !=        | 不等于   |
| &&        | 逻辑与   |
| \|\|      | 逻辑或   |
| ~         | 匹配     |
| !~        | 不匹配   |

## Conditional Statements and Loops

Simple If Statements Syntax.

``` bash
# Simple Action.
if (conditional-expression)
    action

# Multiple Actions.
if (conditional-expression)
{
    action1;
    action2;
}
```

If Else Statement Syntax.

``` bash
# Simple Syntax.
if (conditional-expression)
    action1
else
    action2

# Ternary Operator Syntax.
conditional-expression ? action1 : action2 ;
```

While Loop Syntax.

``` bash
while(condition)
    actions
```

Do-While Loop Syntax.

``` bash
do
action
while(condition)
```

For Loop Syntax.

``` bash
for(initialization;condition;increment/decrement)
actions
```

Additional syntax about loop.

- break
- continue
- exit

## Arrays

Syntax.

``` bash
arrayname[string]=value
```

Browse the Array using For Loop.

``` bash
for (var in arrayname)
actions
```

Delete Array Element.

``` bash
delete arrayname[index];

for (var in array)
   delete array[var]

delete array
```

Multi Dimensional Array.

The `[1,2]` and `["1,2"]` are different.

Sort Array Values using asort.

``` bash
asort(item[, newarray]);
```

Sort Array Indexes using asorti.

``` bash
asorti(state[, newarray]);
```

## Additional Awk Commands

### Pretty Printing Using printf

Syntax.

``` bash
printf "print format", variable1, variable2, etc.
```

Special Characters in the printf Format.

| Special Character | Description |
| :---------------: | :---------: |
| `\n` | 换行 |
| `\t` | Tab |
| `\v` | 竖直 Tab、可递增 |
| `\b` | 回退、删除之前的字符 |
| `\r` | 回车、覆盖之前的打印 |
| `\f` | 效果与 `\v` 类似（猜的）|

### Built-in Numeric Functions

| Function | Description |
| :------: | :---------: |
| `int(n)` | 整数 |
| `log(n)` | 自然对数（即：以 10 为底 n 的对数 |
| `sqrt(n)` | 平方根（注：参数为负数会报错，显示 nan）|
| `exp(n)` | 自然数 e 的 n 次幂 |
| `sin(n)` | n 的正弦 |
| `cos(n)` | n 的余弦 |
| `atan2(m, n)` | m, n 的正切 |

### Random Number Generator

| Function | Description |
| :------: | :---------: |
| `rand()` | 随机生成 0~1 之间的数字 |
| `srand(n)` | 初始化 Generator（即：使 rand() 基于 n 开始随机）|

### Generic String Functions

| Function | Description |
| :------: | :---------: |
| `index(string, char)` | 获取 char 在 string 中的索引位置 |
| `length(string)` | 获取 string 的长度 |
| `split(input-string, output-array, separator)` | 用 separator 切割 input-string 到 output-array |
| `substr(input-string, location, length)` | 从 input-string 的 location 位置提取 length 长度的字符串 |

### GAWK/NAWK String Functions

These string functions are available only in GAWK and NAWK flavors.

| Function | Description |
| :------: | :---------: |
| `sub(original-string, replacement-string, string-variable)` | 替换 string-variable 中的第一个 original-string 为 replacement-string |
| `gsub(original-string, replacement-string, string-variable)` | 替换 string-variable 中的所有 original-string 为 replacement-string |
| `match(input-string, search-string)` | 在 input-string 中搜索 sear-string |

Two special variables about `match()`.

- `RSTART`: search-string 的起始位置
- `RLENGTH`: search-string 的长度

### GAWK String Functions

| Function | Description |
| :------: | :---------: |
| `tolower(string)` | 转化 string 为小写 |
| `toupper(string)` | 转换 string 为大写 |
