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

The following are the built-in variables and their descriptions.

| Variable | Describe |
| :------: | :------: |
| FS | 输入字段分离器 |
| OFS | 输出字段分离器 |
| RS | 输入记录分离器 |
| ORS | 输出记录分离器 |
| NR | 记录数量 |
| FILENAME | 当前文件名称 |
| FNR | 文件记录数量 |

## Variables and Operators

There are no data types in Awk. Whether an awk variable is a number or a string depends on the context in which the variable is used in.

There are Operators for Awk.

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

