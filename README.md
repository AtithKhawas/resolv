#RESOLV:#

Version 1.0

Description:

RESOLV is a domain resolution tool designed for cybersecurity professionals, penetration testers, and network administrators. It resolves domain names into their corresponding IPv4 and IPv6 addresses.

This tool currently supports resolving domains and subdomains from a single input or a file containing a list of domains. It aims to be fast, efficient, and easy to use with command-line options.

Key Features:

Resolves both IPv4 and IPv6 addresses.

Accepts domain inputs via command-line arguments.

Processes bulk domains from an input file.

Displays results with color-coded outputs.

Provides helpful usage instructions and version information.

VISION:

The vision for RESOLV is to evolve into a comprehensive DNS lookup tool for penetration testers and cybersecurity professionals. Future versions will:

Support complete DNS record lookups, including A, AAAA, CNAME, MX, NS, PTR, SRV, SOA, TXT, CAA, DS, and DNSKEY.

Include advanced filtering options for selective lookups (-s).

Provide output-saving capabilities (-o) for structured reporting.

Offer additional customization and automation options.

Encourage contributions to make it a professional and widely used tool.

Usage:

*Basic Usage:*

./resolv example.com  # Resolve a single domain

Process a List of Domains

./resolv -i file.txt  # Resolve domains listed in a file

Display Help

./resolv -h           # Show help message

Check Version

./resolv -v           # Display version information

Installation

Clone the repository:

git clone https://github.com/username/RESOLV.git

Navigate into the directory:

cd RESOLV

Compile the source code:

gcc -o resolv resolv.c

Run the executable:

./resolv example.com

Contribution

Contributions are welcome! If you have suggestions or improvements, feel free to fork this repository and create a pull request. Open issues for bugs or feature requests.

Roadmap:

Expand DNS record lookup features.

Add advanced filtering and output options.

Optimize performance for larger datasets.

Enhance documentation and usability.
