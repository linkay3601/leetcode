# Awk

*Awk* 的使用～

## 目录

   * [Awk](#awk)
      * [目录](#目录)
      * [语法](#语法)
      * [结构](#结构)
      * [内置变量](#内置变量)
      * [流程控制语句](#流程控制语句)
      * [数组](#数组)

## 语法

基础语法。

``` shell
awk -Fs '/pattern/ {action}' input-file
(or)
awk -Fs '{action}' intput-file
```

## 结构

**（1）BEGIN block**

``` shell
BEGIN { awk-commands }
```

**（2）body block**

``` shell
/pattern/ {action}
```

**（3）END block**

``` shell
END { awk-commands }
```

## 内置变量

在 *Awk* 中，没有「数据类型」的说法，*Awk* 中的「数据类型」是根据「上下文」决定的。
在 *Awk* 中，没有「数据类型」的说法，*Awk* 中的「数据类型」是根据「上下文」决定的。

| 变量     | 描述                       |
| :------- | :------------------------- |
| FS       | 输入字段分离器             |
| OFS      | 输出字段分离器             |
| RS       | 输入记录分离器             |
| ORS      | 输出记录分离器             |
| NR       | 记录数量                   |
| FILENAME | 当前文件名称               |
| FNR      | 文件记录数量               |
| SUBSEP   | 自定义 Subscript Separator |

## 流程控制语句

**（1）if** 语句

``` shell
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

**（2）if-else 语句**

``` shell
# Simple Syntax.
if (conditional-expression)
    action1
else
    action2

# Ternary Operator Syntax.
conditional-expression ? action1 : action2 ;
```

**（3）while 语句**

``` shell
while(condition)
    actions
```

**（4）do-while 语句**

``` shell
do
action
while(condition)
```

**（5）for 语句**

``` shell
for(initialization;condition;increment/decrement)
actions
```

关于「循环」的额外语法：
关于「循环」的额外语法：

- break
- continue
- exit

## 数组

**（1）基础语法**

``` shell
arrayname[string]=value
```

**（2）使用 `for` 遍历数组**

``` shell
for (var in arrayname)
actions
```

**（3）删除数组元素**

``` shell
delete arrayname[index];

for (var in array)
   delete array[var]

delete array
```

**（4）多维数组**

在 *Awk* 中，`[1,2]` and `["1,2"]` 使不同的。

使用 `asort` 对数组值进行排序。

``` shell
asort(item[, newarray]);
```

使用 `asorti` 对数组下标进行排序。

``` shell
asorti(state[, newarray]);
```

