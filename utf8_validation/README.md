# UTF-8 Validation

## Project Overview

This project focuses on implementing a method to determine if a given dataset represents a valid UTF-8 encoding. UTF-8 is a variable-width character encoding used for electronic communication, capable of encoding all valid characters in Unicode.

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All files will be interpreted/compiled on **Ubuntu 14.04 LTS** using **python3 (version 3.4.3)**
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/python3`
- A `README.md` file, at the root of the project folder, is mandatory
- Code must follow the **PEP 8** style guide (version 1.7.x)
- All files must be executable

## Method: `validUTF8`

### Prototype

```python
def validUTF8(data: List[int]) -> bool
```

### Functionality

- The function determines if a given dataset is a valid UTF-8 encoding.
- The dataset can contain multiple characters.
- Each integer in the dataset represents 1 byte of data (only the 8 least significant bits are considered).
- A character in UTF-8 can be 1 to 4 bytes long.

### Return

- `True` if the data is a valid UTF-8 encoding.
- `False` otherwise.

## Example

```bash
carrie@ubuntu:~/utf8_validation$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data))  # True

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))  # True

data = [229, 65, 127, 256]
print(validUTF8(data))  # False

carrie@ubuntu:~/utf8_validation$
carrie@ubuntu:~/utf8_validation$ ./0-main.py
True
True
False
```

## Repository

- **GitHub repository:** `holbertonschool-interview`
- **Directory:** `utf8_validation`
- **File:** `0-validate_utf8.py`

## Resources

- [UTF-8](https://en.wikipedia.org/wiki/UTF-8)
- [Characters, Symbols, and the Unicode Miracle](https://www.youtube.com/watch?v=MijmeoH9LT4)

## Author

- **Erwan Lebreton** student at [Holberton School](https://www.holbertonschool.com)
