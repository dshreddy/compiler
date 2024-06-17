%{
    #include "y.tab.h"
    void yyerror(char *);
%}

%option yylineno

%%
    /* variables */
[A-Z]           { yylval = *yytext - 'A'; return ID; }


    /* integers */
[0-9]+          { yylval = atoi(yytext); return INTEGER; }

    /* operators */
[-+()=/*\n]     { return *yytext; }

    /* skip whitespace */
[ \t]           {;}

    /* anything else is an error */
.               { ; }
%%

int yywrap(void) {
    
    return 1;
}