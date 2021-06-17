%%
HOLA:

| VAR_NAME COLON DECLINTEGER COLON EQUAL VAR_NAME SEMICOLON 
	{$$.s = "Declaracion de variable Integer igual a variable"; 
	if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s,"integer")) {
			insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true );
			$$.a = assignAST($6.a);
		} else {yyerror("Variable declared or wrong type");}
	}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL VAR_NAME OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a variable integer + variable integer"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "integer") && checkVarAndType(tabla, size, $8.s, "integer")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) + retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) - retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) * retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) / retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL VAR_NAME OPERATOR OPERATION SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a variable integer + operacion"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "integer") && strcmp($8.type, "integer")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) + $8.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) - $8.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) * $8.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) / $8.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL OPERATION OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a operacion + variable integer"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $8.s, "integer") && strcmp($8.type, "integer")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, $8.i + retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, $8.i - retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, $8.i * retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, $8.i / retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL OPERATION SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a operacion aritmetica"; 
			if (searchVar(tabla, size, $1.s)) {
				$$.error = "empty";insertElement(tabla, &size, $6.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true );$$.a = assignAST($6.a);} else {$$.error = "Variable declared or wrong type";}
	 	}

	| VAR_NAME COLON DECLINTEGER SEMICOLON {
		$$.s = "Declaracion de variable Integer vacia";
		if (searchVar(tabla, size, $1.s)) {
				$$.error = "empty";insertElement(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "integer", false );} else {$$.error = "Variable declared";}
	}

	| VAR_NAME COLON DECLFLOAT COLON EQUAL VAR_NAME SEMICOLON {
			{$$.s = "Declaracion de variable Float igual a variable float"; 
				if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s,"float")) {
				$$.error = "empty";
					insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s), $1.s, false, &elementosOcupados, "float", true );
					$$.a = assignAST($6.a);
				} else {$$.error = "Variable declared or wrong type";}
			}
		}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL VAR_NAME OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable float igual a variable float + variable float"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "float") && checkVarAndType(tabla, size, $8.s, "float")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) + retrieveFloatFromTable(tabla, size, $8.s), $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) - retrieveFloatFromTable(tabla, size, $8.s), $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) * retrieveFloatFromTable(tabla, size, $8.s), $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) / retrieveFloatFromTable(tabla, size, $8.s), $1.s, false, &elementosOcupados, "float", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL VAR_NAME OPERATOR OPERATION SEMICOLON {
			$$.s = "Declaracion de variable float igual a variable float + operacion"; 
			if(searchVar(tabla, size, $1.s) && (checkVarAndType(tabla, size, $6.s, "float") || checkVarAndType(tabla, size, $6.s, "integer"))) {
				$$.error = "empty";
				int isFloat = strcmp($8.type, "float");
				float leftValue = strcmp(getVarType(tabla, size, $6.s), "float") == 0 ? retrieveFloatFromTable(tabla, size, $6.s) : (float)retrieveIntFromTable(tabla, size, $6.s);
				float rightValue = isFloat == 0 ? $8.f : (float)$8.i;
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, 0, "", leftValue + rightValue, $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, 0, "", leftValue - rightValue, $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, 0, "", leftValue * rightValue, $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, 0, "", leftValue / rightValue, $1.s, false, &elementosOcupados, "float", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL OPERATION OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable float igual a operacion + variable float"; 
			if(searchVar(tabla, size, $1.s) && (checkVarAndType(tabla, size, $8.s, "float") || checkVarAndType(tabla, size, $8.s, "integer"))) {
				$$.error = "empty";
				int isFloat = strcmp($6.type, "float");
				float leftValue = isFloat == 0 ? $6.f : (float)$6.i;
				float rightValue = strcmp(getVarType(tabla, size, $8.s), "float") == 0 ? retrieveFloatFromTable(tabla, size, $8.s) : (float)retrieveIntFromTable(tabla, size, $8.s);
				printf("left value: %f\n", leftValue);
				printf("right value: %f\n", rightValue);
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, 0, "", leftValue + rightValue, $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, 0, "", leftValue - rightValue, $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, 0, "", leftValue * rightValue, $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, 0, "", leftValue / rightValue, $1.s, false, &elementosOcupados, "float", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL OPERATION SEMICOLON 
	{$$.s = "Declaracion de variable Float igual a operacion aritmetica";
	if(searchVar(tabla, size, $1.s)) {
				int isFloat = strcmp($6.type, "float");
				$$.error = "empty"; insertElement(tabla, &size, 0, "", isFloat == 0 ? $6.f : (float)$6.i, $1.s, false, &elementosOcupados, "float", true );$$.a = assignAST($6.a);} else {$$.error = "Variable declared or wrong type";}}
	| VAR_NAME COLON DECLFLOAT SEMICOLON {
		$$.s = "Declaracion de variable float vacia";
		if (searchVar(tabla, size, $1.s)) {
				$$.error = "empty";insertElement(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "float", false );} else {$$.error = "Variable declared";}
	}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL VAR_NAME SEMICOLON {
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "boolean")) {
				$$.error = "empty";
				insertElement(tabla, &size, 0, "", 0.0, $1.s, retrieveBoolFromTable(tabla, size, $6.s), &elementosOcupados, "boolean", true );
				$$.a = assignAST($6.a);
			} else {$$.error = "Variable declared or wrong type";}
			$$.s = "Declaracion de variable Boolean a operacion booleana";
		}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL BOOLEAN_OP SEMICOLON {
			if(strcmp($6.error,"empty") == 0 ){
				printf("no errors bool decl with bool op");
				if(searchVar(tabla, size, $1.s)) {
					printf("owo\n");
					$$.error = "empty";
					insertElement(tabla, &size, 0, "", 0.0, $1.s, $6.boo ? true : false, &elementosOcupados, "boolean", true );
					$$.a = assignAST($6.a);
				} else {$$.error = "Variable declared or wrong type";}
			} else {
				$$.error = $6.error;
			}
			
			$$.s = "Declaracion de variable Boolean a operacion booleana";
		}
	| VAR_NAME COLON DECLBOOLEAN SEMICOLON {
			$$.s = "Declaracion de variable Boolean vacia";
			if (searchVar(tabla, size, $1.s)) {
			$$.error = "empty";insertElement(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "boolean", false );} else {$$.error = "Variable declared";}
		}
	| VAR_NAME COLON DECLSTRING COLON EQUAL VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable String igual a variable String"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s,"string")) {
				$$.error = "empty";
				insertElement(tabla, &size, 0, retrieveStringFromTable(tabla, size, $6.s), 0.0, $1.s, false, &elementosOcupados, "string", true );
				$$.a = assignAST($6.a);
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLSTRING COLON EQUAL STRING SEMICOLON {
			$$.s = "Declaracion con string";
			if(searchVar(tabla, size, $1.s)) {
				$$.error = "empty"; insertElement(tabla, &size, 0, $6.s, 0.0, $1.s, false, &elementosOcupados, "string", true );$$.a = assignAST($6.a);} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLSTRING SEMICOLON {
			$$.s = "Declaracion de variable String vacia";
			if (searchVar(tabla, size, $1.s)) {
			$$.error = "empty";insertElement(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "string", false );} else {$$.error = "Variable declared";}
		}
	| VAR_NAME COLON EQUAL VAR_NAME SEMICOLON {
			$$.s = "Asignacion de variable a otra variable";
			if(searchVar(tabla, size, $1.s)) { $$.error = "Assigning to an undeclared variable"; }
			else if(searchVar(tabla, size, $4.s)) {$$.error = "Assigning undeclared variable to existing variable";}
			else if(!searchVar(tabla, size, $1.s) && !searchVar(tabla, size, $4.s)) {
				char* firstVarType = getVarType(tabla, size, $1.s);
				char* secondVarType = getVarType(tabla, size, $4.s);
				if(strcmp(firstVarType, secondVarType) == 0) {
					$$.error = "empty";
					if (firstVarType == "integer") { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $4.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true); }
					else if (firstVarType == "float") { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $4.s), $1.s, false, &elementosOcupados, "float", true); }
					else if (firstVarType == "string") { insertElement(tabla, &size, 0, retrieveStringFromTable(tabla, size, $4.s), 0.0, $1.s, false, &elementosOcupados, "string", true); }
					else if (firstVarType == "boolean") { insertElement(tabla, &size, 0, "", 0.0, $1.s, retrieveBoolFromTable(tabla, size, $4.s), &elementosOcupados, "boolean", true); }
					$$.a = assignAST($4.a);
				} else {
					$$.error = "Uncompatible types";
				}
			}
		} 
	// | VAR_NAME COLON EQUAL VAR_NAME OPERATOR VAR_NAME SEMICOLON {

		}
	| VAR_NAME COLON EQUAL VAR_NAME OPERATOR OPERATION SEMICOLON {$$.s = "Variable igual a Variable operacion con operacion aritmetica";}
	//| VAR_NAME COLON EQUAL VAR_NAME OPERATOR OPERATION2 SEMICOLON {}
	| VAR_NAME COLON EQUAL OPERATION OPERATOR VAR_NAME SEMICOLON {}
	//| VAR_NAME COLON EQUAL OPERATION2 OPERATOR VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL OPERATION SEMICOLON {}
	//| VAR_NAME COLON EQUAL OPERATION2 SEMICOLON {}
	| VAR_NAME COLON EQUAL VAR_NAME BOOLEAN_OP VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL VAR_NAME BOOLEAN_OP INT SEMICOLON {}
	| VAR_NAME COLON EQUAL VAR_NAME BOOLEAN_OP FLOAT SEMICOLON {}
	| VAR_NAME COLON EQUAL INT BOOLEAN_OP VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL FLOAT BOOLEAN_OP VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL BOOLEAN_OP SEMICOLON {}
	| VAR_NAME COLON EQUAL BOOLEAN_VAR SEMICOLON {}
	| VAR_NAME COLON EQUAL STRING SEMICOLON {}

	| TYPE VAR_NAME IS RANGE INT DOTDOT INT SEMICOLON {}
	| TYPE VAR_NAME IS DECLARRAY LEFT INT DOTDOT INT RIGHT OF VAR_NAME SEMICOLON {}
	| VAR_NAME COLON VAR_NAME COLON EQUAL LEFT INT AUXINT RIGHT SEMICOLON {}

	
    
	| VAR_NAME BOOLEAN_OPERATORS OPERATION2 			{
			$$.s = "VAR OP BOOL FLOAT";
			if(!searchVar(tabla, size, $1.s)) {
				$$.error = "empty";
				if(strcmp("integer", getVarType(tabla, size, $1.s)) == 0){
					$$.boo = compare($2.operador, (float)retrieveIntFromTable(tabla, size, $1.s), $3.f);
					$$.a=newast($2.operador, $1.a, $3.a);
				} else if(strcmp("float", getVarType(tabla, size, $1.s))  == 0){
					$$.boo = compare($2.operador, retrieveFloatFromTable(tabla, size, $1.s), $3.f);
					$$.a=newast($2.operador, $1.a, $3.a);
				} else {
					$$.error = "Esta variable tiene un tipo incorrecto";
				}  
				
			} else {$$.error = "Variable declared or wrong type";}
		}
	| OPERATION2 BOOLEAN_OPERATORS VAR_NAME 			{
			$$.s = "FLOAT OP BOOL VAR";
			if(!searchVar(tabla, size, $3.s)) {
				$$.error = "empty";
				if(strcmp("integer", getVarType(tabla, size, $3.s)) == 0){
					$$.boo = compare($2.operador,	$1.f, (float)retrieveIntFromTable(tabla, size, $3.s));
					$$.a=newast($2.operador, $1.a, $3.a);
				} else if(strcmp("float", getVarType(tabla, size, $1.s))  == 0){
					$$.boo = compare($2.operador, $1.f, retrieveFloatFromTable(tabla, size, $3.s));
					$$.a=newast($2.operador, $1.a, $3.a);
				} else {
					$$.error = "Esta variable tiene un tipo incorrecto";
				}  
				
			} else {$$.error = "Variable declared or wrong type";}
		}