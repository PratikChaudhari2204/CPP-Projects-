#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDescription) {
        Task newTask;
        newTask.description = taskDescription;
        newTask.completed = false;
        tasks.push_back(newTask);
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
            return;
        }

        std::cout << "To-Do List:\n";
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex - 1);
            std::cout << "Task removed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    bool isEmpty() {
        return tasks.empty();
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        std::cout << "To-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string taskDescription;
            std::cout << "Enter task description: ";
            std::getline(std::cin, taskDescription);
            todoList.addTask(taskDescription);
        } else if (choice == 2) {
            todoList.viewTasks();
        } else if (choice == 3) {
            int taskNumber;
            todoList.viewTasks();
            std::cout << "Enter task number to mark as completed: ";
            std::cin >> taskNumber;
            todoList.markTaskCompleted(taskNumber);
        } else if (choice == 4) {
            int taskNumber;
            todoList.viewTasks();
            std::cout << "Enter task number to remove: ";
            std::cin >> taskNumber;
            todoList.removeTask(taskNumber);
        } else if (choice == 5) {
            std::cout << "Exiting program...\n";
        } else {
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
