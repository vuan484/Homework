#include<iostream> 
#include<cstring>
using namespace std;

#define BUFFER_SIZE 1024
#define WORDS_BUFFER_SIZE 64
#define WORD_DELIMINITERS " "


/*
    Read the line 
*/
char *read_line(){
    int pos = 0;
    int current_buffer_size = BUFFER_SIZE;
    char *buffer = (char*)malloc(sizeof(char) * current_buffer_size);
    int c; 

    // Fail to allocate memory to the buffer
    if(! buffer){
        cout << "Allocation Error!" << endl;
        exit(1);
    }

    // Read characters until the "\n" or "EOF" (end of file) 
    while(1){
        c = getchar();
        if(c == '\n'){
            buffer[pos] = '\0';
            return buffer;
        }
        else{
            buffer[pos] = c;
        }
        pos++;

        // Reallocate if the line is too long
        if(pos >= BUFFER_SIZE){
            current_buffer_size += BUFFER_SIZE;
            buffer = (char*)realloc(buffer, current_buffer_size);
            if(! buffer){
                cout << "Allocation error!" << endl;
                exit(1);
            }
        }
    }
}

/*
    Split the line into separated words
*/
char **split_line(char *line){
    int current_buffer_size = WORDS_BUFFER_SIZE;
    int pos = 0;
    char **words = (char**)malloc(sizeof(char*) * current_buffer_size);
    char *word;

    if(!words){
        cout << "Allocation error!" << endl;
        exit(1);
    }

    word = strtok(line, WORD_DELIMINITERS);
    while(word != NULL){
        words[pos] = word;
        pos++;

        if(pos >= current_buffer_size){
            current_buffer_size += WORDS_BUFFER_SIZE;
            words = (char**)realloc(words, current_buffer_size * sizeof(char*));
            if(!words){
                cout << "Allocation Error !" << endl;
                exit(1);
            }
        }

        word = strtok(NULL, WORD_DELIMINITERS);
    }
    words[pos] = NULL;
    return words; 
}


int main(){
    char* line; 
    char** words;
    int current_buffer_size = BUFFER_SIZE;
    char* target = (char*)malloc(current_buffer_size*sizeof(char));
    int pos = 0;

    cout << "Enter the line: " << endl;

    // Read the line
    line = read_line();

    // Parse the line 
    words = split_line(line);

    // Concatenate the words
    while(words[pos] != NULL){
        // If the target string needs more memory
        if(strlen(target) + strlen(words[pos]) >= current_buffer_size){
            current_buffer_size += BUFFER_SIZE;
            target = (char*)realloc(target, current_buffer_size * sizeof(char));
        }

        cout << words[pos] << endl;
        strcat(target, words[pos]);
        strcat(target, " ");
        // Duplicate the word if it starts with the letter A or a
        if(words[pos][0] == 'A' || words[pos][0] == 'a'){
            strcat(target, words[pos]);
            strcat(target, " ");
        }
        pos++;
    }

    cout << target << endl;
    return 0;
}