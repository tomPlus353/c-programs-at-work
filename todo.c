#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a task
typedef struct Task {
    char description[100];
    struct Task *next;
} Task;

// Function to add a new task to the list
Task* addTask(Task *head, char *description) {
    // Create a new task
    Task *newTask = (Task *)malloc(sizeof(Task));
    // Copy the description into the new task
    strcpy(newTask->description, description);
    // Set the next pointer of the new task to the current head
    newTask->next = head;
    // Return the new head of the list
    return newTask;
}

// Function to remove a task from the list
Task* removeTask(Task *head, char *description) {
    Task *current = head;
    Task *previous = NULL;
    // Iterate through the list
    while (current != NULL) {
        // If the current task's description matches the one to be removed
        if (strcmp(current->description, description) == 0) {
            // If the task is the head
            if (previous == NULL) {
                head = current->next;
            } else {
                // Otherwise, connect the previous task to the next task
                previous->next = current->next;
            }
            // Free the memory allocated for the removed task
            free(current);
            // Return the updated head
            return head;
        }
        // Move to the next task
        previous = current;
        current = current->next;
    }
    // If the task is not found, return the original head
    return head;
}

// Function to edit a task in the list
Task* editTask(Task *head, char *oldDescription, char *newDescription) {
    Task *current = head;
    // Iterate through the list
    while (current != NULL) {
        // If the current task's description matches the one to be edited
        if (strcmp(current->description, oldDescription) == 0) {
            // Copy the new description into the task
            strcpy(current->description, newDescription);
            // Return the updated head
            return head;
        }
        // Move to the next task
        current = current->next;
    }
    // If the task is not found, return the original head
    return head;
}

// Function to read all tasks in the list
void readTasks(Task *head) {
    Task *current = head;
    // Iterate through the list
    while (current != NULL) {
        // Print the description of each task
        printf("%s\n", current->description);
        // Move to the next task
        current = current->next;
    }
}

int main() {
    Task *head = NULL;
    // Loop to handle user input
    while (1) {
        char command[100];
        char description[100];
        // Get the user command
        printf("Enter command (add, remove, edit, read, quit): ");
        scanf("%s", command);
        // Handle add command
        if (strcmp(command, "add") == 0) {
            printf("Enter task description: ");
            scanf("%s", description);
            head = addTask(head, description);
        }
        // Handle remove command
        else if (strcmp(command, "remove") == 0) {
            printf("Enter task description to remove: ");
            scanf("%s", description);
            head = removeTask(head, description);
        }
        // Handle edit command
        else if (strcmp(command, "edit") == 0) {
            char oldDescription[100];
            printf("Enter task description to edit: ");
            scanf("%s", oldDescription);
            printf("Enter new task description: ");
            scanf("%s", description);
            head = editTask(head, oldDescription, description);
        }
        // Handle read command
        else if (strcmp(command, "read") == 0) {
            readTasks(head);
        }
        // Handle quit command
        else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    // Free all memory allocated for tasks
    Task *current = head;
    while (current != NULL) {
        Task *next = current->next;
        free(current);
        current = next;
    }
    return 0;
}
