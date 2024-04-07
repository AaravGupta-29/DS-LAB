#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char operators[128];
int top1 = -1;

int precedence(char c) {
	if (c == '*' || c == '/') return 3;
	if (c == '+' || c == '-') return 1;
	return -1;
}

char *InfixToPostfix(char *exp) {
	int len = strlen(exp), ri = 0;
	char *res = (char *)malloc(len + 1);

	for (int i = 0; i < len; i++) {
		char c = exp[i];
		if (isalnum(c))
			res[ri++] = c;
		else if (c == '(')
			operators[++top1] = c;
		else if (c == ')') {
			while (top1 != -1 && operators[top1] != '(') res[ri++] = operators[top1--];
			top1--;
		} else {
			while (top1 != -1 && (precedence(c) <= precedence(operators[top1])))
				res[ri++] = operators[top1--];
			operators[++top1] = c;
		}
	}
	while (top1 != -1) res[ri++] = operators[top1--];
	res[ri] = '\0';
	return res;
}

char *PostFixToInfix(char *exp) {
	int len = strlen(exp), ti = -1;
	char *res = (char *)malloc(len + 1), tmp[128][128] = { 0 };

	for (int i = 0; i < len; i++) {
		char c = exp[i];
		if (isalnum(c)) {
			sprintf(tmp[++ti], "%c", c);
		} else {
			char op2[128];
			strcpy(op2, tmp[ti--]);
			char op1[128];
			strcpy(op1, tmp[ti--]);
			sprintf(tmp[++ti], "(%s%c%s)", op1, c, op2);
		}
	}
	strcpy(res, tmp[0]);
	return res;
}

char *InfixToPrefix(char *exp) {
	int len = strlen(exp), ri = 0;
	char *res = (char *)malloc(len + 1);
	exp = strrev(exp);
	for (int i = 0; i < len; i++) {
		if (exp[i] == '(')
			exp[i] = ')';
		else if (exp[i] == ')')
			exp[i] = '(';
	}

	char *postfix = InfixToPostfix(exp);
	postfix = strrev(postfix);
	strcpy(res, postfix);
	free(postfix);
	return res;
}

char *PrefixToInfix(char *exp) {
	int len = strlen(exp), ti = -1;
	char *res = (char *)malloc(len + 1), tmp[128][128] = { 0 };

	for (int i = len - 1; i >= 0; i--) {
		char c = exp[i];
		if (isalnum(c)) {
			sprintf(tmp[++ti], "%c", c);
		} else {
			char op1[128], op2[128];
			strcpy(op1, tmp[ti--]);
			strcpy(op2, tmp[ti--]);
			sprintf(tmp[++ti], "(%s%c%s)", op1, c, op2);
		}
	}
	strcpy(res, tmp[0]);
	return res;
}

int main() {
	char buffer[101];

	printf("Enter Infix expression: ");
	scanf("\n%[^\n]100s", buffer);

	printf("Postfix: %s\n", InfixToPostfix(buffer));
	printf("Prefix: %s\n", InfixToPrefix(buffer));

	printf("Enter Postfix Expression: ");
	scanf("\n%[^\n]100s", buffer);
	printf("Infix: %s\n", PostFixToInfix(buffer));

	printf("Enter Prefix Expression: ");
	scanf("\n%[^\n]100s", buffer);
	printf("Infix: %s\n", PrefixToInfix(buffer));

	return 0;
}
ss
