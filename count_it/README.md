## Resources

**Read or watch**:

- [Reddit API Documentation](/rltoken/R6e5bdJ19xlCk7qxyngEGQ "Reddit API Documentation")

## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
- All your files should end with a new line
- The first line of all your files should be exactly `#!/usr/bin/python3`
- Libraries imported in your Python files must be organized in alphabetical order
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `PEP 8` style
- All your files must be executable
- The length of your files will be tested using `wc`
- All your modules should have a documentation (`python3 -c 'print(__import__("my_module").__doc__)'`)
- You must use the Requests module for sending HTTP requests to the Reddit API

## Tasks

### 4.

Write a _recursive function_ that queries the [Reddit API](/rltoken/R6e5bdJ19xlCk7qxyngEGQ "Reddit API"), parses the title of all hot articles, and prints a sorted count of given keywords (case-insensitive, delimited by spaces. `Javascript` should count as `javascript`, but `java` should not).

Requirements:

- Prototype: `def count_words(subreddit, word_list)`
- Note: You may change the prototype, but it must be able to be called with just a subreddit supplied and a list of keywords. AKA you can add a counter or anything else, but the function must work without supplying a starting value in the main.
- If `word_list` contains the same word (case-insensitive), the final count should be the sum of each duplicate (example below with `java`)
- Results should be printed in descending order, by the count, and if the count is the same for separate keywords, they should then be sorted alphabetically (ascending, from A to Z). Words with no matches should be skipped and not printed. Words must be printed in lowercase.
- Results are based on the number of times a keyword appears, not titles it appears in. `java java java` counts as 3 separate occurrences of `java`.
- To make life easier, `java.` or `java!` or `java_` should not count as `java`
- If no posts match or the subreddit is invalid, print nothing.
- NOTE: Invalid subreddits may return a redirect to search results. Ensure that you are NOT following redirects.

Your code will NOT pass if you are using a loop and not recursively calling the function! This /can/ be done with a loop but the point is to use a recursive function. :)

**Disclaimer**: number presented in this example _cannot be accurate now_ - Reddit is hot articles are always changing.

```
bob@dylan $ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
import sys

if \_\_name\_\_ == '\_\_main\_\_':
    count\_words = \_\_import\_\_('0-count').count\_words
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv\[0\]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv\[0\]))
    else:
        result = count\_words(sys.argv\[1\], \[x for x in sys.argv\[2\].split()\])
bob@dylan $
bob@dylan $ python3 0-main.py programming 'react python java javascript scala no\_results\_for\_this\_one'
java: 27
javascript: 20
python: 17
react: 17
scala: 4
bob@dylan $ python3 0-main.py programming 'JavA java'
java: 54
bob@dylan $ python3 0-main.py not\_a\_valid\_subreddit 'python java javascript scala no\_results\_for\_this\_one'
bob@dylan $ python3 0-main.py not\_a\_valid\_subreddit 'python java'
bob@dylan $
```
