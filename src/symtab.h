

struct symrec {
  char *name;
  int *num;
  char *text;
  char *type;
  struct symrec *next;
};

typedef struct symrec symrec;

symrec *sym_table = (symrec *)0;
symrec *putsymNum ();
symrec *getsymNum ();
symrec *putsymText ();
symrec *getsymText ();

//-----------NUMEROS-------------
symrec * putsymNum ( char *sym_name, int sym_val, char *sym_type ) {
  symrec *ptr;
  ptr = (symrec *) malloc (sizeof(symrec));
  ptr->name = (char *) malloc (strlen(sym_name)+1);
  ptr->num = (int) malloc ((sym_val)+1);
  ptr->type = (char *) malloc (strlen(sym_type)+1);
  strcpy (ptr->name,sym_name);
  ptr->num = sym_val;
  strcpy (ptr->type, sym_type);
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symrec * getsymNum ( char *sym_name, int sym_val) {
  symrec *ptr;

  for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
      sym_val = ptr->num;
	    sym_name = ptr->name;
      return ptr;
    }
  return 0;
}

symrec * updatesymNum ( char *sym_name, int sym_val) {
  symrec *ptr;

  for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
 	    ptr->num = sym_val;
      return ptr;
    }
  return 0;
}

symrec * getvalsymNum ( char *sym_name ) {
  symrec *ptr;

  for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
      return ptr->num;
    }
  return 0;
}

//-----------TEXTOS-------------
symrec * putsymText ( char *sym_name, char *sym_text, char *sym_type  ) {
  symrec *ptr;
  ptr = (symrec *) malloc (sizeof(symrec));
  ptr->name = (char *) malloc (strlen(sym_name)+1);
  ptr->text = (char *) malloc (strlen(sym_name)+1);
  ptr->type = (char *) malloc (strlen(sym_type)+1);
  strcpy (ptr->name,sym_name);
  strcpy (ptr->text,sym_text);
  strcpy (ptr->type, sym_type);

  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symrec * getsymText ( char *sym_name, char *sym_text) {
  symrec *ptr;

  for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
      sym_text = ptr->text;
	    sym_name = ptr->name;
      return ptr;
    }
  return 0;
}

symrec * updatesymText ( char *sym_name, char *sym_text) {
  symrec *ptr;

  for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
 	    ptr->text = sym_text;
      return ptr;
    }
  return 0;
}

symrec * getvalsymText ( char *sym_name ) {
  symrec *ptr;

  for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
      return ptr->text;
    }
  return 0;
}

symrec * gettypesymText ( char *sym_name ) {
  symrec *ptr;
  
  for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0) {
      return ptr->type;
    }
  return 0;
}