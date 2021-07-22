# Sed

流编辑器（Sed）～

## 目录

   * [Sed](#sed)
      * [目录](#目录)
      * [语法](#语法)
      * [区间字符](#区间字符)
      * [替换字符](#替换字符)
      * [选项参考](#选项参考)
      * [命令参考](#命令参考)
      * [脚本](#脚本)

## 语法

**（1）当只有一个「命令」时**

``` shell
sed [options（选项）] {sed-commands（Sed 命令）} {input-file（输入文件）}
```

**（2）当有多个「命令」时**

使用  `-e` 参数。

``` shell
sed [options（选项] -e {sed-command-1（命令 1）} -e {sed-command-2（命令 2）} {input-file（输入文件）}
```

或者使用 `{}`。

``` shell
sed [options（选项）] '{
sed-command-1（命令 1）
sed-command-2（命令 2）
}' input-file （输入文件）
```

使用 `-f` 选项，执行 `Sed` 脚本。

``` shell
sed [options（选项）] -f {sed-commands-in-a-file（Sed 脚本）} {input-file（输入文件）}
```

**（3）替换命令语法**

``` shell
 sed '[address-range|pattern-range（区间）] s/original-string（被替换内容）/replacement-string（替换内容）/[substitute-flags]（替换标识）' inputfile（输入文件）
```

## 区间字符

| 字符  | 描述                 |
| :---- | :------------------- |
| `n`   | 第 n 行              |
| `n,m` | n～m 行              |
| `$`   | 最后一行             |
| `n~m` | n 行开始，每次 `+` m |

## 替换字符

| 字符 | 描述              |
| :--- | :---------------- |
| `&`  | 匹配项            |
| `\n` | 第 n 个组的匹配项 |

## 选项参考

| 选项                | 描述                             |
| :------------------ | :------------------------------- |
| `-n`                | 抑制默认输出                     |
| `-f`                | 执行 *Sed* 脚本                  |
| `-e`                | 执行多个 *Sed* 命令              |
| `-l`                | 与 `l` 命令一起使用，指定行长度  |
| `-c`                | 与 `-i` 一起使用，保留文件所有权 |
| `-i<orig>`          | 修改源文件并备份                 |
| `--in-place=<orig>` | 相当于 `-i<orig>`                |

## 命令参考

| 命令       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| `p`        | 打印 *pattern space*                                         |
| `1,2,3...` | 第 n 个匹配项                                                |
| `w`        | 写入                                                         |
| `i`        | 忽略大小写                                                   |
| `e`        | 执行 *pattern space*                                         |
| `a`        | 在之后添加                                                   |
| `i`        | 在之前插入                                                   |
| `c`        | 替换行                                                       |
| `l`        | 打印隐藏字符                                                 |
| `=`        | 打印行数                                                     |
| `y`        | 大小写转换                                                   |
| `q`        | 退出 *Sed*                                                   |
| `r`        | 读取文件                                                     |
| `n`        | 打印 *pattern space*，改变执行流                             |
| `x`        | 交换 *pattern space* 和 *hold space*                         |
| `h`        | 拷贝 *pattern space* 到 *hold space*                         |
| `H`        | 添加 *pattern space* 到 *hold space*                         |
| `g`        | 拷贝 *hold space* 到 *pattern space*                         |
| `G`        | 拷贝 *hold space* 到 *pattern space*                         |
| `N`        | 添加 next line 到 *pattern space*                            |
| `P`        | 打印 *pattern space* 直到换行（即遇到 \n）                   |
| `D`        | 删除 *pattern space* 直到换行（即遇到 \n）、对剩余部分重新执行 *Sed* 命令 |
| `:lable`   | 定义 lable                                                   |
| `b lable`  | 跳转到 lable                                                 |
| `t lable`  | `s` 命令成功，跳转到 lable                                   |


## 脚本

Shebang。

``` shell
#!/bin/sed -f
```

Shebang 静默模式。

``` shell
#!/bin/sed -nf
or
#n
```

