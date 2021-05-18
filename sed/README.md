# Sed Editor

Document the use of the __Sed Editor__.

- [Sed Editor](#sed-editor)
  * [Sed Syntax](#sed-syntax)
  * [Special Characters](#special-characters)
    + [Options and descriptions](#options-and-descriptions)
    + [Characters about address and their descriptions](#characters-about-address-and-their-descriptions)
    + [Characters about replacement-string and their descriptions](#characters-about-replacement-string-and-their-descriptions)
    + [Commands and descriptions](#commands-and-descriptions)
    + [Commands about hold space and their descriptions](#commands-about-hold-space-and-their-descriptions)
    + [Commands about Multi-Lineand and loops](#commands-about-multi-lineand-and-loops)
  * [Scripts](#scripts)

## Sed Syntax

Syntax when there is only a command.

``` sed
sed [options] {sed-commands} {input-file}
```

Syntax when there are multiple commands.

Use `-e`.

``` bash
sed [options] -e {sed-command-1} -e {sed-command-2} {input-file}
```

Use `{}`

``` bash
sed [options] '{
sed-command-1
sed-command-2
}' input-file
```

Use `-f` option. Execute the Sed script.

``` bash
sed [options] -f {sed-commands-in-a-file} {input-file}
```

Substitute Command Syntax.

``` bash
 sed '[address-range|pattern-range] s/original- string/replacement-string/[substitute-flags]' inputfile
```

## Special Characters

### Options and descriptions

|       Option        |           Description            |
| :-----------------: | :------------------------------: |
|        `-n`         |           抑制默认输出           |
|        `-f`         |         执行 *Sed* 脚本          |
|        `-e`         |       执行多个 *Sed* 命令        |
|        `-l`         |  与 `l`命令一起使用，指定行长度  |
|        `-c`         | 与 `-i` 一起使用，保留文件所有权 |
|     `-i<orig>`      |         修改源文件并备份         |
| `--in-place=<orig>` |        相当于 `-i<orig>`         |

### Characters about address and their descriptions

| Character |    Description     |
| :-------: | :----------------: |
|    `n`    |      第 n 行       |
|   `n,m`   |       n~m 行       |
|    `$`    |      最后一行      |
|   `n~m`   | n 行开始，每次 + m |

### Characters about replacement-string and their descriptions

| Character |    Description    |
| :-------: | :---------------: |
|    `&`    |      匹配项       |
|   `\n`    | 第 n 个组的匹配项 |

### Commands and descriptions

|  Command  |           Description            |
| :-------: | :------------------------------: |
|    `p`    |       打印 *pattern space*       |
| `1,2,3..` |          第 n 个匹配项           |
|    `w`    |               写入               |
|    `i`    |            忽略大小写            |
|    `e`    |       执行 *pattern space*       |
|    `a`    |            在之后添加            |
|    `i`    |            在之前插入            |
|    `c`    |              替换行              |
|    `l`    |           打印隐藏字符           |
|    `=`    |             打印行数             |
|    `y`    |            大小写转换            |
|    `q`    |             退出 *Sed*             |
|    `r`    |             读取文件             |
|    `n`    | 打印 *pattern space*、改变执行流 |

### Commands about hold space and their descriptions

| Command |             Description              |
| :-----: | :----------------------------------: |
|   `x`   | 交换 *pattern space* 和 *hold space* |
|   `h`   | 拷贝 *pattern space* 到 *hold space* |
|   `H`   |   添加 *pattern space* 到 *hold space*   |
|   `g`   |   拷贝 *hold space* 到 *pattern space*   |
|   `G`   |   拷贝 *hold space* 到 *pattern space*   |

### Commands about Multi-Lineand and loops

|  Command  |                         Description                          |
| :-------: | :----------------------------------------------------------: |
|    `N`    |              添加 next line 到 *pattern space*               |
|    `P`    |          打印 *pattern space* 直到换行（即遇到 \n）          |
|    `D`    | 删除 *pattern space* 直到换行（即遇到 \n）、对剩余部分重新执行 *Sed* 命令 |
| `:lable`  |                          定义 lable                          |
| `b lable` |                         跳转到 lable                         |
| `t lable` |                  `s` 命令成功、跳转到 lable                  |

## Scripts

Shebang Line.

``` bash
#!/bin/sed -f
```

Shebang Line. Quit Mode.

``` bash
#!/bin/sed -nf
```

Quit Mode.

``` bash
#n
```

