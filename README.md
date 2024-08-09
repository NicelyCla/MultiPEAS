# MultiPeas

MultiPeas is a modified version of the popular Windows enumeration script `WinPEAS.bat`. The key enhancement in MultiPeas is its ability to invoke a new process for each individual check. This design is specifically aimed at improving compatibility with endpoint protection tools like Crowdstrike Falcon, which may flag certain checks as suspicious. By isolating each check in its own process, MultiPeas ensures that the entire enumeration process is not terminated if a single check is detected and blocked.

## Features

- **Process Isolation:** Each check is run as a separate process, reducing the risk of full script termination by security tools.
- **Comprehensive Enumeration:** Performs the same extensive set of checks as WinPEAS, including privilege escalation vectors, system information, and security configurations.
- **Enhanced Security Tool Evasion:** Designed to reduce the likelihood of detection by endpoint protection tools like Crowdstrike Falcon.

## Why Use MultiPeas?

In environments protected by advanced endpoint detection and response (EDR) solutions, security tools can sometimes prematurely terminate scripts that exhibit suspicious behavior. This can be problematic for penetration testers and red teamers who rely on tools like WinPEAS for reconnaissance and privilege escalation. MultiPeas mitigates this risk by running each check in a separate process. This way, if a specific check is flagged and halted, the rest of the script can continue to run, ensuring that as much information as possible is gathered.

## How It Works

MultiPeas is built upon the original `WinPEAS.bat` script but introduces a fundamental change: instead of running all checks in sequence within a single process, each check is executed as a separate process. Here's a simplified overview of how it works:

1. **Initialization:** MultiPeas begins by setting up the environment and determining which checks to run.
2. **Process Creation:** For each check, MultiPeas spawns a new process. This process runs the specific check, collects the output, and then terminates.
3. **Result Aggregation:** The output from each individual process is collected and displayed in the console, just like in WinPEAS.

## Usage

Make sure the checks.txt file is in the same directory as the executable.
Run MultiPeas as you would run WinPEAS.bat:

```bash
MultiPeass.exe
```

## Notes

- MultiPeas is designed for use in penetration testing and red team engagements. Ensure you have explicit permission to use this tool on any network or system.
- While MultiPeas is intended to improve compatibility with EDR solutions, it is not a guarantee that it will evade all detections. Use responsibly.

## Contributions

Contributions are welcome! Please submit pull requests or report issues

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- [WinPEAS](https://github.com/carlospolop/PEASS-ng) by [Carlos Polop](https://github.com/carlospolop) for the original script and inspiration.
