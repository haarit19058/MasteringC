


## Getline

```c
/* getline:  read a line into s, return length  */ 
int getline(char s[],int lim) 
{ 
   int c, i; 
   for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
	   s[i] = c; 
   if (c == '\n') { 
	   s[i] = c; 
	   ++i; 
   } 
   s[i] = '\0'; 
   return i; 
} 
```

## Copy string

```c
/* copy:  copy 'from' into 'to'; assume to is big enough */ 
void copy(char to[], char from[]) 
{ 
   int i; 
   i = 0; 
   while ((to[i] = from[i]) != '\0') 
	   ++i; 
} 
```

