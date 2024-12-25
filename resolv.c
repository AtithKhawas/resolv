#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to display the banner
void banner() {
sleep (1);
           
printf("****************************************************\n");
printf("*----------------------RESOLVER--------------------*\n");
printf("*++++++++++++++++++++++++++++++++++++++++++++++++++*\n");
printf("*++++++++++++++++++++++++++++++++++++++++++++++++++*\n");
printf("*------------------------------Made by Atith Khawas*\n");
printf("****************************************************\n");
    }
// Function to resolve domain names and print their IP addresses
void resolve_domain(const char *domain) {
    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    // Initialize hints structure
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // Allow both IPv4 and IPv6
    hints.ai_socktype = SOCK_STREAM;

    // Perform DNS resolution
    if ((status = getaddrinfo(domain, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "\033[31m%s: Unable to resolve\033[0m\n", domain);
        return;
    }

    // Print the domain name in green
    printf("\033[32m%s\033[0m\n", domain);

    // Iterate through the results and print each IP address
    for (p = res; p != NULL; p = p->ai_next) {
        void *addr;
        const char *ipver;

        // Check if the result is IPv4 or IPv6
        if (p->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        // Convert the address to a readable string
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("  %s: %s\n", ipver, ipstr);
    }

    // Free the memory allocated by getaddrinfo
    freeaddrinfo(res);
}

// Function to process a file containing a list of domains
void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) > 0) {
            resolve_domain(line);
        }
    }

    fclose(file);
}

// Function to display help message
void print_help() {
    printf("\033[1m\033[34m Resolver\n");
    printf("Usage:\n");
    printf("  -h or --help       Show this help message\n");
    printf("  -i <input file>    Input file with list of domains\n");
    printf("  -v                 Show version\n");
    printf("Example:\n");
    printf("  ./resolv example.com -for single domain\n");
    printf("         ./resolv -i file.txt -for subdomains files\033[0m\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Display the banner at the starting 
    banner();
     // Check if arguments are provided or not
    if (argc < 2) {
        print_help();
        return 1;
    }

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-v") == 0) {
            printf("Basic Resolver Version 1.0\n");
            return 0;
        } else if (strcmp(argv[i], "-i") == 0) {
            if (i + 1 < argc) {
                process_file(argv[i + 1]);
                i++; // Skip the filename arguments
            } else {
                fprintf(stderr, "Error: Missing input file after -i\n");
                return 1;
            }
        } else {
            resolve_domain(argv[i]);
        }
    }

    printf("Mission Successful!\n");
    return 0;
}
