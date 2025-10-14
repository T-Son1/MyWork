#include <stdio.h>
#include <string.h>


void sendMessage(char message[], char chatHistory[100][1000], int *historyCount) {
    printf("You: ");
    fgets(message, 1000, stdin);
     message[strcspn(message, "\n")] = 0;

    if (*historyCount < 100) {
        snprintf(chatHistory[*historyCount], 1000, "You: %s", message);
        (*historyCount)++;
    }
}

void receiveMessage(char message[], char chatHistory[100][1000], int *historyCount) {
    printf("Friend: %s\n", message);

    if (*historyCount < 100) {
        snprintf(chatHistory[*historyCount], 1000, "Friend: %s", message);
        (*historyCount)++;
    }
}

void displayChatHistory(char chatHistory[100][1000], int historyCount) {
    printf("\n--- Chat History ---\n");
    for (int i = 0; i < historyCount; i++) {
        printf("%s\n", chatHistory[i]);
    }
    printf("--------------------\n");
}

int main() {
    char userMessage[1000];
    char friendMessage[1000];
    char chatHistory[100][1000];
    int historyCount = 0;
    int chatting = 1;

    printf("Start chatting (type 'history' to view chat history or 'exit' to quit):\n");

    while (chatting) {
        sendMessage(userMessage, chatHistory, &historyCount);

        if (strcmp(userMessage, "exit") == 0) {
            printf("Chat ended.\n");
            break;
        } else if (strcmp(userMessage, "history") == 0) {
            displayChatHistory(chatHistory, historyCount);
            continue;
        }

        printf("Friend: ");
        fgets(friendMessage, 1000, stdin);
        friendMessage[strcspn(friendMessage, "\n")] = 0;

        if (strcmp(friendMessage, "exit") == 0) {
            printf("Chat ended by your friend.\n");
            break;
        }

        receiveMessage(friendMessage, chatHistory, &historyCount);
    }

    return 0;
}
