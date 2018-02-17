# cs113_Spring_2018

__INSTALLATION:__

* `git clone https://github.com/david-topham/cs113_spring_2018.git ttgen`
* `make -C ttgen install`
* 'ttgen [OPTION] <BOOLEAN EXPRESSION>`

**OPTION:**
* `-d, --detailed` Includes all subpropositions of given proposition.
* `-h, --hline`    Prints a horizontal line between each permutation.
* `-m, --mute`     Prints without the table environment.
* `-r, --reverse`  Prints reverse order for TT rows.
* `-c, --circuits` Prints 0/1 instead of F/T.
* `-s, --sort`     Prints alphabetical order.
*     `--help`     Prints this text.

**BOOLEAN EXPRESSION:**
* `[A-Z] [a-z]` Available letters
* `'(' ')'`     To denote parentheses.
* `~`   'NOT' logic operator
* `&`   'AND' logic operator
* `|`   'OR' logic operator
* `^`   'XOR' logic operator
* `->`  'IMPLY' logic operator
* `<->` 'IF AND ONLY IF' logic operator
