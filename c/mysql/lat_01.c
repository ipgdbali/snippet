//MYSQL Snippet Code
//Latihan 01
//Basic client operation
//Listing Database for supplied host, username and password

#include <stdio.h>
#include <mysql.h>

int main(int argc,char * argv[])
{
	MYSQL inst;
	MYSQL_RES *result;
	MYSQL_ROW row;

	if(argc != 4)
	{
		printf("usage : %s <host> <username> <password>\n",argv[0]);
		return -1;
	}

	mysql_init(&inst);
	// Connecting to MySQL Server
	if(!mysql_real_connect(&inst,argv[1],argv[2],argv[3],NULL,0,NULL,0))
	{
		fprintf(stderr,"Error Connecting %s",mysql_error(&inst));
		return -1;
	}

	if(0 != mysql_query(&inst,"SHOW DATABASES"))
	{
		fprintf(stderr,"Error Querying  %s",mysql_error(&inst));
		return -1;
	};

	//Use Result
	result = mysql_use_result(&inst);
	if(!result)
	{
		fprintf(stderr,"No Data is Gathered%s",mysql_error(&inst));
		return -1;
	}


	printf("List Database : \n");
	while(row = mysql_fetch_row(result))
	{
		printf("%s\n",row[0]);
	};


	mysql_free_result(result);

	//Close Connection
	mysql_close(&inst);

	return 0;
}
