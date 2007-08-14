/* Processed by ecpg (regression mode) */
/* These include files are added by the preprocessor */
#include <ecpgtype.h>
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */
#define ECPGdebug(X,Y) ECPGdebug((X)+100,(Y))

#line 1 "array_of_struct.pgc"
#include <stdio.h>


#line 1 "regression.h"






#line 3 "array_of_struct.pgc"


/* exec sql whenever sqlerror  sqlprint ; */
#line 5 "array_of_struct.pgc"

/* exec sql whenever sql_warning  sqlprint ; */
#line 6 "array_of_struct.pgc"

/* exec sql whenever not found  sqlprint ; */
#line 7 "array_of_struct.pgc"


typedef  struct { 
#line 12 "array_of_struct.pgc"
   struct varchar_name_12  { int len; char arr[ 50 ]; }  name    ;
 
#line 13 "array_of_struct.pgc"
 int  phone    ;
 }   customer ;
#line 14 "array_of_struct.pgc"


typedef  struct ind { 
#line 19 "array_of_struct.pgc"
 short  name_ind    ;
 
#line 20 "array_of_struct.pgc"
 short  phone_ind    ;
 }   cust_ind ;
#line 21 "array_of_struct.pgc"


int main( int argc, char * argv[] )
{
    /* exec sql begin declare section */
        
        
       
      
         
             
       typedef struct { 
#line 30 "array_of_struct.pgc"
   struct varchar_name_30  { int len; char arr[ 50 ]; }  name    ;
 
#line 31 "array_of_struct.pgc"
 int  phone    ;
 }  customer2 ;

#line 32 "array_of_struct.pgc"

        
       
      
         
             
       
       
      
         
             
       
       
    
#line 26 "array_of_struct.pgc"
 customer  custs1 [ 10 ]    ;
 
#line 27 "array_of_struct.pgc"
 cust_ind  inds [ 10 ]    ;
  
#line 33 "array_of_struct.pgc"
 customer2  custs2 [ 10 ]    ;
 
#line 38 "array_of_struct.pgc"
 struct customer3 { 
#line 36 "array_of_struct.pgc"
   struct varchar_name_36  { int len; char arr[ 50 ]; }  name    ;
 
#line 37 "array_of_struct.pgc"
 int  phone    ;
 }  custs3 [ 10 ]    ;
 
#line 43 "array_of_struct.pgc"
 struct customer4 { 
#line 41 "array_of_struct.pgc"
   struct varchar_name_41  { int len; char arr[ 50 ]; }  name    ;
 
#line 42 "array_of_struct.pgc"
 int  phone    ;
 }  custs4    ;
 
#line 44 "array_of_struct.pgc"
 int  r    ;
/* exec sql end declare section */
#line 45 "array_of_struct.pgc"


    ECPGdebug(1, stderr);
	  
    { ECPGconnect(__LINE__, 0, "regress1" , NULL, NULL , NULL, 0); 
#line 49 "array_of_struct.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 49 "array_of_struct.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 49 "array_of_struct.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, 0, "create  table customers ( c varchar ( 50 )    , p int   )    ", ECPGt_EOIT, ECPGt_EORT);
#line 51 "array_of_struct.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 51 "array_of_struct.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 51 "array_of_struct.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, 0, "insert into customers values ( 'John Doe' , '12345' ) ", ECPGt_EOIT, ECPGt_EORT);
#line 52 "array_of_struct.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) sqlprint();
#line 52 "array_of_struct.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 52 "array_of_struct.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 52 "array_of_struct.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, 0, "insert into customers values ( 'Jane Doe' , '67890' ) ", ECPGt_EOIT, ECPGt_EORT);
#line 53 "array_of_struct.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) sqlprint();
#line 53 "array_of_struct.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 53 "array_of_struct.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 53 "array_of_struct.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, 0, "select  *  from customers     limit 2 ", ECPGt_EOIT, 
	ECPGt_varchar,&(custs1->name),(long)50,(long)10,sizeof( customer ), 
	ECPGt_short,&(inds->name_ind),(long)1,(long)10,sizeof( struct ind ), 
	ECPGt_int,&(custs1->phone),(long)1,(long)10,sizeof( customer ), 
	ECPGt_short,&(inds->phone_ind),(long)1,(long)10,sizeof( struct ind ), ECPGt_EORT);
#line 55 "array_of_struct.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) sqlprint();
#line 55 "array_of_struct.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 55 "array_of_struct.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 55 "array_of_struct.pgc"

    printf("custs1:\n");
    for (r = 0; r < 2; r++)
    {
	    printf( "name  - %s\n", custs1[r].name.arr );
	    printf( "phone - %d\n", custs1[r].phone );
    }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, 0, "select  *  from customers     limit 2 ", ECPGt_EOIT, 
	ECPGt_varchar,&(custs2->name),(long)50,(long)10,sizeof( customer2 ), 
	ECPGt_short,&(inds->name_ind),(long)1,(long)10,sizeof( struct ind ), 
	ECPGt_int,&(custs2->phone),(long)1,(long)10,sizeof( customer2 ), 
	ECPGt_short,&(inds->phone_ind),(long)1,(long)10,sizeof( struct ind ), ECPGt_EORT);
#line 63 "array_of_struct.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) sqlprint();
#line 63 "array_of_struct.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 63 "array_of_struct.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 63 "array_of_struct.pgc"

    printf("\ncusts2:\n");
    for (r = 0; r < 2; r++)
    {
	    printf( "name  - %s\n", custs2[r].name.arr );
	    printf( "phone - %d\n", custs2[r].phone );
    }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, 0, "select  *  from customers     limit 2 ", ECPGt_EOIT, 
	ECPGt_varchar,&(custs3->name),(long)50,(long)10,sizeof( struct customer3 ), 
	ECPGt_short,&(inds->name_ind),(long)1,(long)10,sizeof( struct ind ), 
	ECPGt_int,&(custs3->phone),(long)1,(long)10,sizeof( struct customer3 ), 
	ECPGt_short,&(inds->phone_ind),(long)1,(long)10,sizeof( struct ind ), ECPGt_EORT);
#line 71 "array_of_struct.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) sqlprint();
#line 71 "array_of_struct.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 71 "array_of_struct.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 71 "array_of_struct.pgc"

    printf("\ncusts3:\n");
    for (r = 0; r < 2; r++)
    {
	    printf( "name  - %s\n", custs3[r].name.arr );
	    printf( "phone - %d\n", custs3[r].phone );
    }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, 0, "select  *  from customers     limit 1 ", ECPGt_EOIT, 
	ECPGt_varchar,&(custs4.name),(long)50,(long)1,sizeof(struct varchar_name_41), 
	ECPGt_short,&(inds[0].name_ind),(long)1,(long)1,sizeof(short), 
	ECPGt_int,&(custs4.phone),(long)1,(long)1,sizeof(int), 
	ECPGt_short,&(inds[0].phone_ind),(long)1,(long)1,sizeof(short), ECPGt_EORT);
#line 79 "array_of_struct.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) sqlprint();
#line 79 "array_of_struct.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 79 "array_of_struct.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 79 "array_of_struct.pgc"

    printf("\ncusts4:\n");
    printf( "name  - %s\n", custs4.name.arr );
    printf( "phone - %d\n", custs4.phone );

    { ECPGdisconnect(__LINE__, "ALL");
#line 84 "array_of_struct.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 84 "array_of_struct.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 84 "array_of_struct.pgc"


    return( 0 );
}
