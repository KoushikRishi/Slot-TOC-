#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10
#define MAX_TRANSITIONS 10

typedef struct {
    int transitions[MAX_TRANSITIONS];
    bool epsilon;
} State;

void findEpsilonClosure(State nfa[], int numStates, int currentState, bool visited[]) {
    if (visited[currentState]) return;
    visited[currentState] = true;
    printf("%d ", currentState);
    if (nfa[currentState].epsilon)
        for (int i = 0; nfa[currentState].transitions[i] != -1; i++)
            findEpsilonClosure(nfa, numStates, nfa[currentState].transitions[i], visited);
}

int main() {
    State nfa[MAX_STATES] = {
        {{1, 2, -1}, true}, {{3, 4, -1}, false}, {{5, -1}, false}, {{-1}, false},
        {{6, -1}, false}, {{7, -1}, false}, {{-1}, false}, {{-1}, false}
    };
    int numStates = 8;

    printf("e-Closure for each state in the NFA:\n");
    for (int i = 0; i < numStates; i++) {
        bool visited[MAX_STATES] = {false};
        printf("e-Closure(%d): ", i);
        findEpsilonClosure(nfa, numStates, i, visited);
        printf("\n");
    }

    return 0;
}														







