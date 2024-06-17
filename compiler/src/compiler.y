%{	
	#include<bits/stdc++.h>
    #include"lexer.cpp"
	using namespace std;
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();

    extern int lineNo;
	extern FILE *yyin; // Declare yyin to point to the input file

	// Symbol table 
    struct symbolTableNode{

        string dataType;
        string type;
        int lineNo;
		int m;
		int n;
    };
	unordered_map<string, symbolTableNode>symbolTable;

    void insert(string);
	void insert(string,int);
	void insert(string,int,int);
	int lookUp(string);
    void insertType();
    string type;

	struct node{

		string nodeType;
        string data;
		int iVal;
		float fVal;
        node *l;
        node *r;

    };

    struct node * root = nullptr;
    struct node * mknode(struct node*, struct node*, string);
	struct node * mknode(struct node*, struct node*, string, int);
	struct node * mknode(struct node*, struct node*, string, float);
    void preorder(node*, int);

	// MIPS
	string mips = "";
	string gvarMIPS = "";
	string mainStartMIPS = "";
	string mainBodyMIPS = "";
	string mainEndMIPS = "";

	bool cantHandle = false;
	bool cantHandleString = "None";
%}

%union { 

	struct var_name { 

		char name[100]; 
		int val;
		float fval;
        struct node *nd;

	} nd_obj; 

}

%token <nd_obj> BEG END
%token <nd_obj> DECL BEGDECL ENDDECL
%token <nd_obj> T_INT T_FLOAT
%token <nd_obj> READ WRITE
%token <nd_obj> IF THEN ELSE ENDIF FOR WHILE BREAK
%token <nd_obj> RET
%token <nd_obj> ID NUM FLOAT
%token <nd_obj> EQEQ LE GE NE INCR

%type <nd_obj> Programme GlobalDeclSec GlobalDeclList 
%type <nd_obj> GlobalDecl RetType GlobalIDList GlobalID 
%type <nd_obj> StmtList Stmt AssignStmt WriteStmt ReadStmt VarExpr StrExpr Expr 
%type <nd_obj> ExprList VarExprList IfStmt ElseStmt ForStmt WhileStmt
%type <nd_obj> Forcond1 Forcond2 Forcond3

%left '<' '>'
%left EQEQ LE GE NE
%left '+' '-'
%left '*' '/'
%left '%'
%nonassoc UMINUS

%%
	Programme:	GlobalDeclSec  BEG StmtList END { $$.nd = mknode($1.nd, $3.nd, "Programme"); root = $$.nd; }
			;

    // ----------------- Globale declaration section related rules start here -----------------
	RetType:	T_INT   				{ type = yytext; $$.nd = mknode(NULL,NULL,"INT"); }
		   |    T_FLOAT					{ type = yytext; $$.nd = mknode(NULL,NULL,"FLOAT"); }			
		   ;

	GlobalID:	ID      					
			{ 
				insert($1.name);  
				$$.nd = mknode(NULL,NULL,$1.name);  
			}		
			| 	ID '[' NUM ']'  			
			{ 
				insert($1.name, $3.val);  
				$$.nd = mknode(mknode(NULL,NULL,"NUM",$3.val), NULL, $1.name);
			}
			|   ID '[' NUM ']' '[' NUM ']'  
			{ 
				insert($1.name, $3.val, $6.val);  
				$$.nd = mknode(mknode(NULL,NULL,"NUM",$3.val), mknode(NULL,NULL,"NUM",$6.val), $1.name); 
			}
			;

	GlobalIDList:	GlobalID                      
			  { 
				$$.nd = $1.nd; 
			  }
			  |	GlobalID ',' GlobalIDList         
			  { 
				$$.nd = mknode($1.nd, $3.nd, " "); 
			  }
			  ;
	
	GlobalDecl:	RetType GlobalIDList ';'		  
			  { 
				$$.nd = mknode($1.nd, $2.nd, "GlobalDecl"); 
			  }				
		 	  ;

	GlobalDeclList: /* NULL */					  { $$.nd = NULL; }
				  | GlobalDecl GlobalDeclList     { $$.nd = mknode($1.nd,$2.nd, "GDecList"); }
				  ;

	GlobalDeclSec:	DECL GlobalDeclList ENDDECL   { $$.nd = mknode($2.nd, nullptr, "GlobalDeclSec"); }
			 	 ;
	
	// ----------------- Main body related rules starts here  -----------------
	Expr:	NUM 							{ $$.nd = mknode(NULL,NULL,"NUM",$1.val); }
		|   FLOAT 							{ $$.nd = mknode(NULL,NULL, "FLOAT",$1.fval); }
		|	VarExpr						    { $$.nd = mknode($1.nd,NULL, "VarExpr"); }
		|	VarExpr INCR					{ $$.nd = mknode($1.nd,NULL, "Post Incr"); }
		|	INCR VarExpr					{ $$.nd = mknode($2.nd,NULL, "Pre Incr"); }
		|	'(' Expr ')'					{ $$.nd = mknode($2.nd,NULL,"()"); }
		|	Expr '+' Expr 					{ $$.nd = mknode($1.nd,$3.nd, "+"); }
		|	Expr '-' Expr	 				{ $$.nd = mknode($1.nd,$3.nd, "-"); }
		|	Expr '*' Expr 					{ $$.nd = mknode($1.nd,$3.nd, "*"); }
		|	Expr '/' Expr 					{ $$.nd = mknode($1.nd,$3.nd, "/"); }
		|	Expr '%' Expr 					{ $$.nd = mknode($1.nd,$3.nd, "%"); }
		|	Expr '<' Expr					{ $$.nd = mknode($1.nd,$3.nd, "<"); }
		|	Expr '>' Expr					{ $$.nd = mknode($1.nd,$3.nd, ">"); }
        |   Expr EQEQ Expr                  { $$.nd = mknode($1.nd,$3.nd, "=="); }
        |   Expr GE Expr                    { $$.nd = mknode($1.nd,$3.nd, ">="); }
        |   Expr LE Expr                    { $$.nd = mknode($1.nd,$3.nd, "<="); }
        |   Expr NE Expr                    { $$.nd = mknode($1.nd,$3.nd, "!="); }
		;
	
	ExprList: /* NULL */						{ $$.nd = NULL; }
			| Expr 								{ $$.nd = $1.nd; }	
			| Expr ',' ExprList 				{ $$.nd = mknode($1.nd, $3.nd, "ExprList"); }

	VarExpr:  ID					   			{ $$.nd = mknode(NULL,NULL,$1.name); }
           |  ID '[' Expr ']'          			{ $$.nd = mknode($3.nd, NULL, $1.name); }
		   |  ID '[' Expr ']' '[' Expr ']' 		{ $$.nd = mknode($3.nd, $6.nd, $1.name); }
		   ;
	
	VarExprList:	VarExpr                         { $$.nd = $1.nd; }
			   |	VarExpr ',' VarExprList         { $$.nd = mknode($1.nd, $3.nd, "VarExprList"); }
			   ;

	AssignStmt:	VarExpr '=' Expr { $$.nd = mknode($1.nd,$3.nd, "="); }
			  ;
	
	StrExpr:  ID                          { $$.nd = $1.nd; }
        	| StrExpr ID   			      { $$.nd = mknode($1.nd, $2.nd, "StrExpr"); }
        	;

	ReadStmt:	READ '(' VarExprList ')' 		{ $$.nd = mknode($3.nd, NULL, "READ"); }
		     ;

	WriteStmt:	WRITE '(' ExprList ')' 		{ $$.nd = mknode($3.nd, NULL, "WRITE"); }
			 |  WRITE '(''"' StrExpr '"'')'     { $$.nd = mknode($4.nd, NULL, "WRITE"); }
		     ;

    ElseStmt: /* NULL */                      { $$.nd = NULL; }
            | ELSE '{' StmtList '}'           { $$.nd = mknode($3.nd, NULL, "ELSE"); }
            ;
        
    IfStmt: IF '(' Expr ')' '{' StmtList '}' ElseStmt  { $$.nd = mknode($3.nd, mknode($6.nd, $8.nd, " "), "IF"); }
          ;
	
	Forcond1: /* NULL */ { $$.nd = NULL; }
			| AssignStmt { $$.nd = mknode($1.nd, NULL, "Forcond1"); }
			; 

	Forcond2: /* NULL */ { $$.nd = NULL; }
			| AssignStmt { $$.nd = mknode($1.nd, NULL, "Forcond2"); }
			| Expr 		 { $$.nd = mknode($1.nd, NULL, "Forcond2"); }
			; 

	Forcond3: /* NULL */ { $$.nd = NULL; }
			| AssignStmt { $$.nd = mknode($1.nd, NULL, "Forcond3"); }
			| Expr 		 { $$.nd = mknode($1.nd, NULL, "Forcond3"); }
			; 


    ForStmt: FOR '(' Forcond1 ';' Forcond2 ';' Forcond3 ')' '{' StmtList '}'    
	{ 
		$$.nd = mknode($3.nd, mknode($5.nd, mknode($7.nd, mknode($10.nd, NULL, " "), " "), " "), "FOR"); 
	}
           ;
	
	WhileStmt: WHILE '(' Expr ')' '{' StmtList '}'
		{ 
			$$.nd = mknode($3.nd, mknode($6.nd, NULL, " "), "WHILE"); 
		}
			 ; 
	
	Stmt:	AssignStmt  ';'			{ $$.nd = $1.nd; }
		|   ReadStmt ';'			{ $$.nd = $1.nd; }
		|	WriteStmt ';'			{ $$.nd = $1.nd; }		
		|   IfStmt                  { $$.nd = $1.nd; }
        |   ForStmt                 { $$.nd = $1.nd; }
		|   WhileStmt				{ $$.nd = $1.nd; }
        |   BREAK ';' 	            { $$.nd = mknode(NULL, NULL, "BREAK"); }		
		;

	StmtList:	/* NULL */	  { $$.nd = NULL; }
			|	Stmt StmtList 
			{ 
				$$.nd = mknode($1.nd, $2.nd, "StmtList"); 
				// preorder($1.nd); 
				// cout<<"\n";
			}
			;
%%

string removeExtension(string fileName) {
	
    size_t dotPos = fileName.find_last_of('.');
    if (dotPos != std::string::npos) {
        return fileName.substr(0, dotPos);
    } else {
        // No dot found, return the original file name
        return fileName;
    }
}

class MIPSCodeGenerator {
public:

    void generateMIPS(node* root, const char* inputFileName) {

        if(root == nullptr) return;

		if(root->data == "Programme"){

			gvarMIPS += "\t.file\t1 \""+string(inputFileName)+"\""+"\n";
			gvarMIPS += "\t.section .mdebug.abi32\n\t.previous\n\t.nan\tlegacy\n\t.module fp=xx\n\t.module nooddspreg\n\t.abicalls\n\t.text\n";

			generateGlobalDeclMIPS(root->l);

			if(root->r){
				genrateStmtListMIPS(root->r);
			} //

			if(mainStartMIPS == ""){

				mainStartMIPS+= "\t.text\n"
				"\t.align\t2\n"
				"\t.globl\tmain\n"
				"\t.set\tnomips16\n"
				"\t.set\tnomicromips\n"
				"\t.ent\tmain\n"
				"\t.type\tmain, @function\n"
				"main:\n"
				"\t.frame\t$fp,8,$31\t\t# vars= 0, regs= 1/0, args= 0, gp= 0\n"
				"\t.mask\t0x40000000,-4\n"
				"\t.fmask\t0x00000000,0\n"
				"\t.set\tnoreorder\n"
				"\t.set\tnomacro\n"
				"\taddiu\t$sp,$sp,-8\n"
				"\tsw\t$fp,4($sp)\n"
				"\tmove\t$fp,$sp\n";

			} //

			if(mainEndMIPS == ""){

				mainEndMIPS += "\tmove\t$2,$0\n"
				"\tmove\t$sp,$fp\n"
				"\tlw\t$fp,4($sp)\n"
				"\taddiu\t$sp,$sp,8\n"
				"\tjr\t$31\n"
				"\tnop\n\n"
				"\t.set\tmacro\n"
				"\t.set\treorder\n"
				"\t.end\tmain\n"
				"\t.size\tmain, .-main\n"
				"\t.ident\t\"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0\"\n"
				"\t.section\t.note.GNU-stack,\"\",@progbits\n";

			} //
		} else {
			cout<<"---- Syntax error in input programme ----\n";
		}
    }

private:
	int gvarLabel = 0, temp = 0, forLabel = 2, ifLabel = 2;
	unordered_map<int,bool> regAvailability = {
		{3, true},
		{4, true},
		{5, true},
		{6, true},
		{7, true},
		{8, true},
		{9, true},
		{10, true},
		{11, true},
		{12, true},
		{13, true},
		{14, true},
		{15, true},
		{16, true},
		{17, true},
		{18, true},
		{19, true},
		{20, true},
	}; // 

	void generateGlobalDeclMIPS(node* root) {

		if (root == nullptr) return;

		// Traverse the left subtree to process the first global declaration
		// currently at GlobalDeclSec node
		// one node left gives us GlobalDeclList

		// if GlobalDeclList is NULL then just return cause there are no global declarations
		if(root->l == nullptr) return;

		// The following nodes can't be null (cause of the way we declared grammer)
		// one node left to GlobalDeclList gives us first GlobalDecl
		// one node right to GlobalDecl gives us the integer declarations
		// if there are more than one inteneger declarations then root->l->l->r would be " "
		// else it would be name of first declaraed variable
		if(root->l->l->r->data == " "){
			generateGVarMIPS(true, root->l->l->r->l);
			node * temp = root->l->l->r->r;
			while(temp){
				if(temp->data == " ") {
					generateGVarMIPS(false, temp->l);
					temp = temp->r;
				} else {
					generateGVarMIPS(false, temp);
					break;
				} // 
			} // 
		} else generateGVarMIPS(true, root->l->l->r);

		// Now we are done with the first GlobalDecl, the remaining global declaration doesn't need any speacial attention
		node *temp = root->l->r;
		while(temp){

			// We are at GDecList node now, one node left is GDecl
			node *temp1 = temp->l->r;
			while(temp1){
				if(temp1->data == " ") {
					generateGVarMIPS(false, temp1->l);
					temp1 = temp1->r;
				} else {
					generateGVarMIPS(false, temp1);
					break;
				} //
			} //

			temp = temp->r;
		} 
	} // 

	void generateGVarMIPS(bool first, node *varNode) {
		if(first){
			if(varNode->l== NULL && varNode->r == NULL){

				// Normal intege or float variable
				string varName = varNode->data;

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.section\t.bss,\"aw\",@nobits\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", 4\n" +
				varName + ":\n"
				"\t.space\t4\n";

			} else if (varNode->r == NULL){

				// 1D array
				string varName = varNode->data;
				string size = to_string(4*varNode->l->iVal);

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.section\t.bss,\"aw\",@nobits\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", " + size + "\n" +
				varName + ":\n"
				"\t.space\t"+ size +"\n";
			} else {

				// 2D array
				string varName = varNode->data;
				string size = to_string(4*varNode->l->iVal*varNode->r->iVal);

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.section\t.bss,\"aw\",@nobits\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", " + size + "\n" +
				varName + ":\n"
				"\t.space\t"+ size +"\n";
			} //

		} else{
			
			if(varNode->l== NULL && varNode->r == NULL){

				// Normal intege or float variable
				string varName = varNode->data;

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", 4\n" +
				varName + ":\n"
				"\t.space\t4\n";

			} else if (varNode->r == NULL){

				// 1D array
				string varName = varNode->data;
				string size = to_string(4*varNode->l->iVal);

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", " + size + "\n" +
				varName + ":\n"
				"\t.space\t"+size+"\n";
			} else {

				// 2D array
				string varName = varNode->data;
				string size = to_string(4*varNode->l->iVal*varNode->r->iVal);

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", " + size + "\n" +
				varName + ":\n"
				"\t.space\t"+size+"\n";
			} //
		}
	} // 

	void genrateStmtListMIPS(node *rt) {

		if(rt == nullptr) return;

		if(rt->l->data == "WRITE"){

			if(gvarLabel == 0) {
				gvarMIPS += "\t.rdata\n"
				"\t.align\t2\n"
				"$LC"+to_string(gvarLabel++)+":\n"   // label name variable
				"\t.ascii\t\"" + "%d" + "\\000\"\n";
			} // 

			if(mainStartMIPS == ""){

				mainStartMIPS+= "\t.text\n"
				"\t.align\t2\n"
				"\t.globl\tmain\n"
				"\t.set\tnomips16\n"
				"\t.set\tnomicromips\n"
				"\t.ent\tmain\n"
				"\t.type\tmain, @function\n"
				"main:\n"
				"\t.frame\t$fp,32,$31\t\t# vars= 0, regs= 1/0, args= 0, gp= 0\n"
				"\t.mask\t0xc0000000,-4\n"
				"\t.fmask\t0x00000000,0\n"
				"\t.set\tnoreorder\n"
				"\t.set\tnomacro\n"
				"\taddiu\t$sp,$sp,-32\n"
				"\tsw\t$31,28($sp)\n"
				"\tsw\t$fp,24($sp)\n"
				"\tmove\t$fp,$sp\n"
				"\tlui\t$28,%hi(__gnu_local_gp)\n"
				"\taddiu\t$28,$28,%lo(__gnu_local_gp)\n"
				"\t.cprestore\t16\n";

			} // 

			node* temp = rt->l->l;

			while(temp){

				regAvailability[4] = false;
				regAvailability[5] = false;

				int resultReg;

				if(temp->data == "ExprList")  resultReg = generateExprMIPS(temp->l);
				else resultReg = generateExprMIPS(temp);

				mainBodyMIPS += "\tmove\t$5,$"+to_string(resultReg)+"\n"
				"\tlui\t$2,%hi($LC0)\n"
				"\taddiu\t$4,$2,%lo($LC0)\n"
				"\tlw\t$2,%call16(printf)($28)\n"
				"\tmove\t$25,$2\n"
				"\t.reloc\t1f,R_MIPS_JALR,printf\n"
				"1:\tjalr\t$25\n"
				"\tnop\n\n"
				"\tlw\t$28,16($fp)\n";

				mainBodyMIPS += "\tli\t$4,10			# 0xa\n"
				"\tlw\t$2,%call16(putchar)($28)\n"
				"\tmove\t$25,$2\n"
				"\t.reloc\t1f,R_MIPS_JALR,putchar\n"
				"1:\tjalr\t$25\n"
				"\tnop\n\n"
				"\tlw\t$28,16($fp)\n";

				regAvailability[4] = true;
				regAvailability[5] = true;

				if(temp->data == "ExprList") temp = temp->r;
				else break;
			} // 

			if(mainEndMIPS == "") {

				mainEndMIPS += "\tmove\t$2,$0\n"
				"\tmove\t$sp,$fp\n"
				"\tlw\t$31,28($sp)\n"
				"\tlw\t$fp,24($sp)\n"
				"\taddiu\t$sp,$sp,32\n"
				"\tjr\t$31\n"
				"\tnop\n\n"
				"\t.set\tmacro\n"
				"\t.set\treorder\n"
				"\t.end\tmain\n"
				"\t.size\tmain, .-main\n"
				"\t.ident\t\"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0\"\n"
				"\t.section\t.note.GNU-stack,\"\",@progbits\n";
			} // 

		} else if(rt->l->data == "READ") {
			
			if(gvarLabel == 0) {
				gvarMIPS += "\t.rdata\n"
				"\t.align\t2\n"
				"$LC"+to_string(gvarLabel++)+":\n"   // label name variable
				"\t.ascii\t\"" + "%d" + "\\000\"\n";
			} // 

			if(mainStartMIPS == ""){

				mainStartMIPS+= "\t.text\n"
				"\t.align\t2\n"
				"\t.globl\tmain\n"
				"\t.set\tnomips16\n"
				"\t.set\tnomicromips\n"
				"\t.ent\tmain\n"
				"\t.type\tmain, @function\n"
				"main:\n"
				"\t.frame\t$fp,32,$31\t\t# vars= 0, regs= 1/0, args= 0, gp= 0\n"
				"\t.mask\t0xc0000000,-4\n"
				"\t.fmask\t0x00000000,0\n"
				"\t.set\tnoreorder\n"
				"\t.set\tnomacro\n"
				"\taddiu\t$sp,$sp,-32\n"
				"\tsw\t$31,28($sp)\n"
				"\tsw\t$fp,24($sp)\n"
				"\tmove\t$fp,$sp\n"
				"\tlui\t$28,%hi(__gnu_local_gp)\n"
				"\taddiu\t$28,$28,%lo(__gnu_local_gp)\n"
				"\t.cprestore\t16\n";

			} // 

			node* temp = rt->l->l;

			while(temp){

				regAvailability[4] = false;
				regAvailability[5] = false;

				int resultReg;

				if(temp->data == "VarExprList")  resultReg = generateExprMIPS(mknode(temp->l, NULL, "__isoc99_scanf"));
				else resultReg = generateExprMIPS(mknode(temp, NULL, "__isoc99_scanf"));

				mainBodyMIPS += "\tmove\t$5,$"+to_string(resultReg)+"\n"
				"\tlui\t$2,%hi($LC0)\n"
				"\taddiu\t$4,$2,%lo($LC0)\n"
				"\tlw\t$2,%call16(__isoc99_scanf)($28)\n"
				"\tmove\t$25,$2\n"
				"\t.reloc\t1f,R_MIPS_JALR,__isoc99_scanf\n"
				"1:\tjalr\t$25\n"
				"\tnop\n\n"
				"\tlw\t$28,16($fp)\n";

				regAvailability[4] = true;
				regAvailability[5] = true;

				if(temp->data == "VarExprList") temp = temp->r;
				else break;
			} // 

			if(mainEndMIPS == "") {

				mainEndMIPS += "\tmove\t$2,$0\n"
				"\tmove\t$sp,$fp\n"
				"\tlw\t$31,28($sp)\n"
				"\tlw\t$fp,24($sp)\n"
				"\taddiu\t$sp,$sp,32\n"
				"\tjr\t$31\n"
				"\tnop\n\n"
				"\t.set\tmacro\n"
				"\t.set\treorder\n"
				"\t.end\tmain\n"
				"\t.size\tmain, .-main\n"
				"\t.ident\t\"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0\"\n"
				"\t.section\t.note.GNU-stack,\"\",@progbits\n";
			} // 
		} else if(rt->l->data == "="){

			// Variable on LHS
			if(rt->l->l->l == NULL && rt->l->l->r == NULL){

				int resultReg = generateExprMIPS(rt->l->r);
				// Assuming $3 contains the result of the RHS expression
				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->l->data+")\n"
				"\tsw\t$"+to_string(resultReg)+",%lo("+rt->l->l->data+")($2)\n";

			} // 1D Array on LHS 
			else if (rt->l->l->r == NULL) {

				int indexExprResultReg, rHSExprResultReg;

				indexExprResultReg = generateExprMIPS(rt->l->l->l); 

				regAvailability[indexExprResultReg] = false;

				rHSExprResultReg = generateExprMIPS(rt->l->r); 

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->l->data+")\n"
				"\taddiu\t$2,$2,%lo("+rt->l->l->data+")            # $2 contains address(a)\n"
				"\tsll\t$"+to_string(indexExprResultReg)+",$"+to_string(indexExprResultReg)+",2\n"
				"\taddu\t$2,$2,$"+to_string(indexExprResultReg)+"\n"
				"\tsw\t$"+to_string(rHSExprResultReg)+",0($2)\n";

				regAvailability[indexExprResultReg] = true;

			} else{
				cantHandle = true;
				cantHandleString = "2D array is used in the programme\n";
			} //
		} else if(rt->l->data == "FOR"){

			forLabel += 3;

			// For condition 1
			if(rt->l->l && rt->l->l->data == "Forcond1") genrateStmtListMIPS(rt->l->l);
			mainBodyMIPS += "\t.option\tpic0  # Assemble for position-independent code\n"
			"\tb\t$L"+to_string(forLabel-3)+"  # Branch to (loop check)\n"
			"\tnop\n\n"
			"\t.option\tpic2  # Assemble for absolute code\n"
			"$L"+to_string(forLabel-2)+":   # Loop start\n";
			"\tnop\n\n";

			// For loop body
			genrateStmtListMIPS(rt->l->r->r->r->l);

			// For condition 3
			if(rt->l->r->r->l && rt->l->r->r->l->data == "Forcond3"){
				if(rt->l->r->r->l->l->data == "=") genrateStmtListMIPS(rt->l->r->r->l);
				else generateExprMIPS(rt->l->r->r->l->l);
			} // 

			// For condition 2
			mainBodyMIPS += "$L"+to_string(forLabel-3)+": # Loop check\n";
			"\tnop\n\n";
			if(rt->l->r->l && rt->l->r->l->data == "Forcond2") {
				if(rt->l->r->l->l->data == "=") {
					genrateStmtListMIPS(rt->l->r->l);
					mainBodyMIPS += "\tbeq\t$0,$0,$L"+to_string(forLabel-2)+"\n";
					"\tnop\n\n";
				} else {
					int resultReg = generateExprMIPS(rt->l->r->l->l);
					mainBodyMIPS += "\tbne\t$"+to_string(resultReg)+",$0,$L"+to_string(forLabel-2)+"\n";
				} // 
			} // 
			mainBodyMIPS += "\tnop\n\n";
			mainBodyMIPS += "$L"+to_string(forLabel-1)+":\n";
			"\tnop\n\n";

		} else if(rt->l->data == "IF") {

			ifLabel += 2;

			// Confition MIPS
			int conditionResultReg = generateExprMIPS(rt->l->l);
			mainBodyMIPS += "\tbeq\t$"+to_string(conditionResultReg)+",$0,$LL"+to_string(ifLabel-2)+"\n"
			"\tnop\n\n";

			// If Body MIPS
			genrateStmtListMIPS(rt->l->r->l);
			mainBodyMIPS += "\t.option\tpic0\n"
			"\tb\t$LL"+to_string(ifLabel-1)+"\n"
			"\tnop\n\n"
			"\t.option\tpic2\n"
			"$LL"+to_string(ifLabel-2)+":\n";
			"\tnop\n\n";

			// Else body MIPS
			if(rt->l->r->r) genrateStmtListMIPS(rt->l->r->r->l);
			mainBodyMIPS += "$LL"+to_string(ifLabel-1)+":\n";
			"\tnop\n\n";

		} else if(rt->l->data == "BREAK"){
			mainBodyMIPS += "\tbeq\t$0,$0,$L"+to_string(forLabel-1)+"\n"
			"\tnop\n\n";
		}

		genrateStmtListMIPS(rt->r);
	} //

	int generateExprMIPS(node *rt) {

		if(rt == nullptr) return -2;

		int returnReg = -1;
		for(auto it = regAvailability.begin(); it!=regAvailability.end(); it++){
			if(it->second){
				returnReg = it->first;
				break;
			} // 
		}// 
		if(returnReg == -1){

			cantHandle = true;
			cantHandleString = "Register limit reacher";
			return -1;
		} //
		regAvailability[returnReg] = false;

		if(rt->data == "NUM" || rt->data == "FLOAT"){

			mainBodyMIPS += "\tli\t$"+to_string(returnReg)+","+to_string(rt->iVal)+"\n";

		} else if (rt->data == "VarExpr") {

			// Variable
			if(rt->l->l == NULL && rt->l->r == NULL){

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->data+")\n"
				"\tlw\t$"+to_string(returnReg)+",%lo("+rt->l->data+")($2)\n";

			} // 1D Array
			else if(rt->l->r == NULL) {

				int indexExprResultReg = generateExprMIPS(rt->l->l); 

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->data+")\n"
				"\taddiu\t$2,$2,%lo("+rt->l->data+")\n"
				"\tsll\t$"+to_string(indexExprResultReg)+",$"+to_string(indexExprResultReg)+",2\n"
				"\taddu\t$2,$2,$"+to_string(indexExprResultReg)+"\n"
				"\tlw\t$"+to_string(returnReg)+",0($2)\n";

			} else {

				cantHandle = true;
				cantHandleString = "2D array is used in programme\n";
			} //

		} else if (rt->data == "__isoc99_scanf"){

			// Variable
			if(rt->l->l == NULL && rt->l->r == NULL){

				mainBodyMIPS += "\tlui\t$"+to_string(returnReg)+",%hi("+rt->l->data+")\n"
				"\taddiu\t$"+to_string(returnReg)+",$"+to_string(returnReg)+",%lo("+rt->l->data+")\n";

			} // 1D Array
			else if(rt->l->r == NULL) {

				int indexExprResultReg = generateExprMIPS(rt->l->l); 
				mainBodyMIPS += "\tlui\t$"+to_string(returnReg)+",%hi("+rt->l->data+")\n"
				"\taddiu\t$"+to_string(returnReg)+",$"+to_string(returnReg)+",%lo("+rt->l->data+")\n"
				"\tsll\t$"+to_string(indexExprResultReg)+",$"+to_string(indexExprResultReg)+",2\n"
				"\taddu\t$"+to_string(returnReg)+",$"+to_string(returnReg)+",$"+to_string(indexExprResultReg)+"\n";

			} else {

				cantHandle = true;
				cantHandleString = "2D array is used in programme\n";
			} //

		} else if (rt->data == "+") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tadd\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";

		} else if (rt->data == "-") {
			
			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsub\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";

		} else if (rt->data == "*") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tmul\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == "/") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tdiv\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == "%") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\trem\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == "<") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tslt\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == ">") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsgt\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		}  else if (rt->data == "==") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tseq\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		}  else if (rt->data == ">=") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsge\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		}  else if (rt->data == "<=") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsle\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		}  else if (rt->data == "!=") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsne\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == "()") {
			regAvailability[returnReg] = true;
			returnReg = generateExprMIPS(rt->l);
		} else if (rt->data == "Pre Incr") {

			// Variable
			if(rt->l->l == NULL && rt->l->r == NULL){

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->data+")\n"
				"\tlw\t$2,%lo("+rt->l->data+")($2)\n" // $2 = variable
				"\taddiu\t$"+to_string(returnReg)+",$2,1\n" // returnReg = variable + 1
				"\tlui\t$2,%hi("+rt->l->data+")\n"    
				"\tsw\t$"+to_string(returnReg)+",%lo("+rt->l->data+")($2)\n"; // save incremented value in memeory

			} // 1D Array
			else if(rt->l->r == NULL) {

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->data+")\n"
				"\taddiu\t$2,$2,%lo("+rt->l->data+")\n"
				"\tlw\t$2,"+to_string(4*rt->l->l->iVal)+"($2)\n" // $2 = variable
				"\taddiu\t$"+to_string(returnReg)+",$2,1\n" // returnReg = variable + 1
				"\tlui\t$2,%hi("+rt->l->data+")\n"    
				"\taddiu\t$2,$2,%lo("+rt->l->data+")\n"
				"\tsw\t$"+to_string(returnReg)+","+to_string(4*rt->l->l->iVal)+"($2)\n";


			} else {
				cout<<"Reached here 4\n";

				cantHandle = true;
				cantHandleString = "2D array is used in programme\n";
			} //

		} else if (rt->data == "Post Incr") {
			
			// Variable
			if(rt->l->l == NULL && rt->l->r == NULL){

				mainBodyMIPS += "\tlui\t$" + to_string(returnReg) + ",%hi(" + rt->l->data + ")\n"
                "\tlw\t$" + to_string(returnReg) + ",%lo("+rt->l->data+")($" + to_string(returnReg) + ")\n" // returnReg = variable
				"\taddiu\t$2,$"+to_string(returnReg)+",1\n" // $2 = variable + 1 
				"\tlui\t$" + to_string(returnReg) + ",%hi("+rt->l->data+")\n"
                "\tsw\t$2,%lo("+rt->l->data+")($" + to_string(returnReg) + ")\n" // save incremented value in memory
				"\taddiu\t$"+to_string(returnReg)+",$2,-1\n"; // returnReg = variable

			} // 1D Array
			else if(rt->l->r == NULL) {

				int indexExprResultReg = generateExprMIPS(rt->l->l); 
				mainBodyMIPS += "\tlui\t$" + to_string(returnReg) + ",%hi(" + rt->l->data + ")\n"
                "\taddiu\t$" + to_string(returnReg) + ",$" + to_string(returnReg) + ",%lo(" + rt->l->data + ")\n"
				"\tlw\t$" + to_string(returnReg) + "," + to_string(4 * rt->l->l->iVal) + "($" + to_string(returnReg) + ")\n" // returnReg = variable
				"\taddiu\t$2,$" + to_string(returnReg) + ",1\n" // $2 = variable + 1
				"\tlui\t$" + to_string(returnReg) + ",%hi("+rt->l->data+")\n"
                "\taddiu\t$" + to_string(returnReg) + ",$" + to_string(returnReg) + ",%lo(" + rt->l->data + ")\n"
                "\tsw\t$2," + to_string(4 * rt->l->l->iVal) + "($" + to_string(returnReg) + ")\n" // save incremented value in memory
				"\taddiu\t$"+to_string(returnReg)+",$2,-1\n"; // returnReg = variable


			} else {

				cantHandle = true;
				cantHandleString = "2D array is used in programme\n";
			} //

		} // 

		regAvailability[returnReg] = true;
		return returnReg;
	} //
};

void insert(string id) {

  if(!lookUp(yytext)) {

        symbolTableNode newEntry;
        newEntry.dataType = type;
		newEntry.type = "Variable";
        newEntry.lineNo = lineNo;
		newEntry.m = 0;
		newEntry.n = 0;
        symbolTable[id] = newEntry;
    }
} // 

void insert(string id, int m) {

  if(!lookUp(yytext)) {

	symbolTableNode newEntry;
    newEntry.dataType = type;
	newEntry.type = "1D Array";
	newEntry.m = m;
	newEntry.n = 0;
    newEntry.lineNo = lineNo;
    symbolTable[id] = newEntry;
  }
}

void insert(string id, int m, int n) {

  if(!lookUp(yytext)) {

	symbolTableNode newEntry;
    newEntry.dataType = type;
	newEntry.type = "2D Array";
	newEntry.m = m;
	newEntry.n = n;
    newEntry.lineNo = lineNo;
    symbolTable[id] = newEntry;
  }
}

// return if id is already is there or not in symbol table
int lookUp(string id) {
    return symbolTable.count(id) > 0;
}

void insertType() {
	type = yytext;
}

struct node * mknode(struct node *l, struct node *r, string s){

    node * newNode = new struct node;
    newNode->l = l;
    newNode->r = r;
    newNode->data = s;

    return newNode;
}

struct node * mknode(struct node *l, struct node *r, string s, int iVal){

    node * newNode = new struct node;
    newNode->l = l;
    newNode->r = r;
    newNode->data = s;
	newNode->iVal = iVal;

    return newNode;
}

struct node * mknode(struct node *l, struct node *r, string s, float fVal){

    node * newNode = new struct node;
    newNode->l = l;
    newNode->r = r;
    newNode->data = s;
	newNode->fVal = fVal;

    return newNode;
}

void preorder(node* rt, int depth) {
    if (rt == nullptr) return;

		for (int i = 0; i < depth; ++i) {
			cout << "    ";
		}
		cout << rt->data << "\n";

    preorder(rt->l, depth + 1);  // Print left subtree
    preorder(rt->r, depth + 1);  // Print right subtree
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

int main(int argc, char *argv[]) {

	if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");

    if (!inputFile) {
        std::cerr << "Error: Unable to open input file " << argv[1] << std::endl;
        return 1;
    }

    yyin = inputFile;

    yyparse();

	cout<<"\n\t\t\tSYMBOL TABLE \n";
	cout<<"\nID        DATATYPE         TYPE         LINE NUMBER\n";
	cout<<"_________________________________________________________________________\n\n";

	
	for(auto it = symbolTable.begin(); it != symbolTable.end(); it++) {

        cout<<it->first<<"\t"<<it->second.dataType<<"\t"<<it->second.type<<"\t"<<it->second.lineNo<<"\t"<<"("<<it->second.m<<","<<it->second.n<<")"<<"\n";
    }
    cout<<"\n";

    cout<<"\n\n";
	cout<<"\t\t\tSYNTAXT TREE PREORDER TRAVERSAL\n\n";
    preorder(root,0);

	MIPSCodeGenerator().generateMIPS(root, argv[1]);
	mips = gvarMIPS + mainStartMIPS + mainBodyMIPS + mainEndMIPS;

	// Output file for MIPS code
    std::ofstream outputFile(removeExtension(string(argv[1]))+".s");
	if(!cantHandle) {
		outputFile<<mips;
	} else{
		outputFile<<cantHandleString;
	}
	outputFile.close();

	fclose(inputFile);
	return 0;
}