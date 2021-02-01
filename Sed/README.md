# Sed Editor

Document the use of the __Sed Editor__.

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

The following are the options and descriptions.

| Option | Describe |
| :----: | :------: |
| `-n` | 抑制默认输出 |
| `-f` | 执行 Sed 脚本 |
| `-e` | 执行多个 Sed 命令 |
| `-l` | 与 `l`命令一起使用，指定行长度 |
| `-c` | 与 `-i` 一起使用，保留文件所有权 |
| `-i<orig>` | 修改源文件并备份 |
| `--in-place=<orig>` | 相当于 `-i<orig>` |

The following are the address and patterns and their descriptions.

| Symbol | Describe |
| :----: | :------: |
| `n` | 第 n 行 |
| `n,m` | n ~ m 行 |
| `$` | 最后一行 |
| `n~m` | n 行开始，每次 + m |

The following are the special characters of replacement-string and their descriptions.

| Symbol | Describe |
| :----: | :------: |
| `&` | 匹配项 |
| `\n` | 第 n 个组的匹配项 |

The following are the flags and descriptions.

| Flag | Describe |
| :--: | :------: |
| `p` | 打印 pattern space |
| `1,2,3..` | 第 n 个匹配项 |
| `w` | 写入 |
| `i` | 忽略大小写 |
| `e` | 执行 pattern space |
| `a` | 在之后添加 |
| `i` | 在之前插入 |
| `c` | 替换行 |
| `l` | 打印隐藏字符 |
| `=` | 打印行数 |
| `y` | 大小写转换 |
| `q` | 退出 Sed |
| `r` | 读取文件 |
| `n` | 打印 pattern space、改变执行流 |

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
