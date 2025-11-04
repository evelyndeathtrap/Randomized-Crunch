#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    
    FILE* fp = fopen("/dev/urandom", "rb");
    if (fp == NULL) {
        perror("Failed to open /dev/urandom");
        return 1;
    }
    
    
    while(1) {
            int buf_size = rand() %  atoi(argv[2]) + atoi(argv[1]);
    char* buf = malloc(buf_size);

        size_t bytes_read = fread(buf, 1, buf_size, fp);
        if (bytes_read > 0) {
            fwrite(buf, 1, bytes_read, stdout);
            printf("\n");
        }
        free(buf);        
        // Optional: Add a way to break the loop
        // For example, after some iterations or on user input
    }
    
    // Cleanup (though this infinite loop never reaches here)
    fclose(fp);
    return 0;
}
