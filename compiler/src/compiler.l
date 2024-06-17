%{    
    #include<bits/stdc++.h>
    using namespace std;
    #include "parser.hpp"  
    int lineNo = 0;       
%}

digit	[0-9]
letter	[a-zA-Z]

%%
"//"[^"\n]*                                 {   
                                                // Ignore comments 
                                                lineNo++;
                                            }
"begin"			                            { 
                                                // cout<<"BEG\t";
                                                return BEG; 
                                            }	
"end"							            { 
                                                // cout<<"END\t";
                                                return END; 
                                            }
"decl"							            { 
                                                // cout<<"DECL\t";
                                                return DECL; 
                                            }
"begindecl"                                 { 
                                                // cout<<"BEGDECL\t";
                                                return BEGDECL;  
                                            }
"enddecl"						            { 
                                                //cout<<"ENDDECL\t";
                                                return ENDDECL; 
                                            }
"integer" 			                        { 
                                                //cout<<"T_INT\t";
                                                return T_INT; 
                                            }
"float" 			                        { 
                                                //cout<<"T_FLOAT\t";
                                                return T_FLOAT;
                                            }
"read"                                      { 
                                                //cout<<"READ\t";
                                                return READ; 
                                            }
"write"							            { 
                                                //cout<<"WRITE\t";
                                                return WRITE; 
                                            }	
"for" 				                        {
                                                //cout<<"FOR\t"; 
                                                return FOR; 
                                            }
"while" 				                    {
                                                //cout<<"WHILE\t"; 
                                                return WHILE; 
                                            }
"if"				                        { 
                                                //cout<<"IF\t";
                                                return IF; 
                                            }
"then"                                      { 
                                                //cout<<"THEN\t";
                                                return THEN; 
                                            }
"else"				                        { 
                                                //cout<<"ELSE\t";
                                                return ELSE; 
                                            }	
"endif"				                        { 
                                                //cout<<"ENDIF\t";
                                                return ENDIF; 
                                            }
"break"                                     { 
                                                //cout<<"BREAK\t";
                                                return BREAK; 
                                            }
"return"                                    { 
                                                //cout<<"RET\t";
                                                return RET; 
                                            }
{letter}({letter}|{digit})*                 { 
                                                //cout<<"ID"<<"\t";
                                                strcpy(yylval.nd_obj.name,(yytext)); 
                                                return ID; 
                                            }
[\-+]?{digit}+            			        { 
                                                //cout<<"NUM"<<"\t";
                                                yylval.nd_obj.val = stoi(yytext); 
                                                return NUM; 
                                            }
[\-+]?{digit}*[0-9.]{digit}*			    { 
                                                //cout<<"NUM"<<"\t";
                                                yylval.nd_obj.fval = stof(yytext); 
                                                return FLOAT; 
                                            }
"++"                                        {
                                                return INCR;
                                            }
[\-|'/'|'+'|'*'|'='|'<'|'>'|'%'|'!']        { 
                                                //cout<<yytext<<"\t";
                                                return *yytext; 
                                            }
"\n"                                        {   
                                                //cout<<"\n";
                                                lineNo++;   
                                            }
"=="				                        { 
                                                return EQEQ; 
                                            }	
"<="				                        { 
                                                return LE; 
                                            }
">="				                        { 
                                                return GE; 
                                            }
"!="				                        { 
                                                return NE; 
                                            }
["]                                         {   
                                                ;  
                                            }
[ \t]			                            {   
                                                /* skip white spaces */
                                                ;  
                                            } 
.				                            {
                                                // cout<<yytext<<"\t";
                                                return *yytext;  
                                            }		
%%

int yywrap() {
    return 1;
}

// int main() {
//     cout<<"\n";
//     yylex();
//     cout<<"\n";
// }