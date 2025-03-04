# Log Parsing

## Description

This project involves creating a Python script (`0-stats.py`) that reads logs from standard input line by line and computes metrics based on the input format. The script processes HTTP request logs and outputs statistics after every 10 lines or upon receiving a keyboard interruption (CTRL + C).

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All files must be interpreted/compiled on **Ubuntu 14.04 LTS** using **Python 3.4.3**
- All files should end with a new line
- The first line of all scripts must be `#!/usr/bin/python3`
- A `README.md` file is mandatory at the root of the project folder
- Code must adhere to **PEP 8 style** (version **1.7.x**)
- All files must be executable
- File length will be tested using `wc`

## Input Format

Each log entry follows this format:

```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

- `<IP Address>`: A valid IPv4 address
- `<date>`: The date and time of the request
- `<status code>`: HTTP response status code (e.g., 200, 301, 400, etc.)
- `<file size>`: Size of the file sent in the response

If a line does not match this format, it is skipped.

## Output Format

After every 10 lines and/or a keyboard interruption (`CTRL + C`), the script prints:

- **Total file size:** Sum of all `<file size>` values encountered so far.
- **Status code counts:** The number of occurrences of each status code encountered, displayed in ascending order.

Example output:

```
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
```

## Implementation Details

- The script reads from **stdin**.
- Uses a counter to keep track of processed lines.
- Maintains a dictionary to count occurrences of specific HTTP status codes.
- Handles **KeyboardInterrupt (CTRL + C)** to print final stats before exiting.

## Usage

To run the script, use a log generator (e.g., `0-generator.py`) to simulate log entries:

```sh
./0-generator.py | ./0-stats.py
```

## Example Repository Structure

```
log_parsing/
├── 0-generator.py
├── 0-stats.py
├── README.md
```

## Author

- **Alexa Orrico**, Software Engineer at Holberton School
- **Erwan Lebreton** Students Holberton School
