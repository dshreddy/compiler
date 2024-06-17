%token INTEGER ID
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%{
    #include<stdio.h>
    void yyerror(char *);
    extern int yylineno;
    int yylex(void);
    int sym[26];
%}

%%
program:
    program stmt '\n'
    |
    ;
stmt:
    expr { printf("%d\n", $1); }
    | ID '=' expr { sym[$1] = $3; }
    ;
expr:
    INTEGER
    | ID { $$ = sym[$1]; }
    | '-' expr %prec UMINUS { $$ = 0-$2; }
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | '(' expr ')' { $$ = $2; }
    ;
%%

void yyerror(char *s) {

    fprintf(stderr, "line %d: %s\n",yylineno-1, s);
    return;
}

int main(void) {
    yyparse();
    return 0;
}