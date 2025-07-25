## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
- All your files should end with a new line
- The first line of all your files should be exactly `#!/usr/bin/python3`
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `PEP 8` style (version 1.7.x)
- You are not allowed to import any module
- All modules and functions must be documented
- All your files must be executable

## Tasks

### 1.

Given an `n` x `n` 2D matrix, rotate it 90 degrees clockwise.

- Prototype: `def rotate_2d_matrix(matrix):`
- Do not return anything. The matrix must be edited **in-place**.
- You can assume the matrix will have 2 dimensions and will not be empty.

```
jessevhedden$ cat main\_0.py
#!/usr/bin/python3
"""
Test  - Rotate 2D Matrix
"""
rotate\_2d\_matrix = \_\_import\_\_('0-rotate\_2d\_matrix').rotate\_2d\_matrix

if \_\_name\_\_ == "\_\_main\_\_":
    matrix = \[\[1, 2, 3\],
              \[4, 5, 6\],
              \[7, 8, 9\]\]

    rotate\_2d\_matrix(matrix)
    print(matrix)

jessevhedden$
jessevhedden$ ./main\_0.py
\[\[7, 4, 1\],
\[8, 5, 2\],
\[9, 6, 3\]\]
jessevhedden$
```
