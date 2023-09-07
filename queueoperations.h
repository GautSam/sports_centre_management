
static int node_count = 0;
static int chesstime,crickettime,carromtime,tennistime;              //used to give static time
char chess[SIZE][80];
static int frontchess=-1, rearchess=-1;      						//for chess booking
char cricket[SIZE][80];
static int frontcricket = -1, rearcricket = -1;						//for cricket booking
char carrom[SIZE][80];
static int frontcarrom = -1, rearcarrom = -1;  						//for carrom booking
char tennis[SIZE][80];
static int fronttennis = -1, reartennis = -1;						//for tabletennis booking



//add member booking to chess
void enqueuechess() {
	char name[30];

	printf("\n\t\t\t\t WITH WHAT NAME YOU WANT TO DO BOOKING   : ");
	scanf(" %[^\n]s",name);
	if (rearchess == SIZE - 1){
		printf("\n\t\t\t\tTODAY'S BOOKING IS FULL, PLEASE DO ENQUIRE TOMORROW'!!");
		chesstime++;
	}
		
	else {

		if (frontchess == -1)
			frontchess = 0;
		rearchess++;
		strcpy(chess[rearchess],name);
		chesstime++;

	}
	if(chesstime==1) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CHESS                |\n");
		printf("\t\t\t\t|\t TIME : 10.30 am - 11.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	} else if(chesstime==2) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CHESS                |\n");
		printf("\t\t\t\t|\t TIME : 11.30 am - 12.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	} else if(chesstime==3) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CHESS                |\n");
		printf("\t\t\t\t|\t TIME : 3.30 am - 4.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	}
	else if(chesstime==4) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CHESS                |\n");
		printf("\t\t\t\t|\t TIME : 4.30 am - 5.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	}
	printf("\n\n");
}


//adding element in cricket queue
void enqueuecricket() {
	char name[30];

	printf("\n\t\t\t\tWITH WHAT NAME YOU WANT TO DO BOOKING   : ");
	scanf(" %[^\n]s",name);
	if (rearcricket == SIZE - 1)
		printf("\n\t\t\t\tTODAY'S BOOKING IS FULL, PLEASE DO ENQUIRE TOMORROW'!!");
	else {

		if (frontcricket == -1)
			frontcricket = 0;
		rearcricket++;
		strcpy(cricket[rearcricket],name);
		crickettime++;

	}
	if(crickettime==1) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CRICKET              |\n");
		printf("\t\t\t\t|\t TIME : 10.30 am - 11.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	} else if(crickettime==2) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CRICKET              |\n");
		printf("\t\t\t\t|\t TIME : 11.30 am - 12.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	} else if(crickettime==3) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CRICKET            |\n");
		printf("\t\t\t\t|\t TIME : 3.30 am - 4.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	}
	else if(crickettime==4) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CRICKET            |\n");
		printf("\t\t\t\t|\t TIME : 4.30 am - 5.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	}
}


//adding element in carrom queue
void enqueuecarrom() {
	char name[30];

	printf("\n\t\t\t\tWITH WHAT NAME YOU WANT TO DO BOOKING   : ");
	scanf(" %[^\n]s",name);
	if (rearcarrom == SIZE - 1)
		printf("\n\t\t\t\tTODAY'S BOOKING IS FULL, PLEASE DO ENQUIRE TOMORROW'!!");
	else {

		if (frontcarrom == -1)
			frontcarrom = 0;
		rearcarrom++;
		strcpy(carrom[rearcarrom],name);
		carromtime++;

	}
	if(carromtime==1) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CARROM               |\n");
		printf("\t\t\t\t|\t TIME : 10.30 am - 11.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	} else if(carromtime==2) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CARROM               |\n");
		printf("\t\t\t\t|\t TIME : 11.30 am - 12.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	} else if(carromtime==3) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CARROM             |\n");
		printf("\t\t\t\t|\t TIME : 3.30 am - 4.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	}
	else if(carromtime==4) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : CARROM             |\n");
		printf("\t\t\t\t|\t TIME : 4.30 am - 5.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	}
}


//adding element in table-tennis queue
void enqueuetennis() {
	char name[30];

	printf("\n\t\t\t\tWITH WHAT NAME YOU WANT TO DO BOOKING   : ");
	scanf(" %[^\n]s",name);
	if (reartennis == SIZE - 1)
		printf("\n\t\t\t\tTODAY'S BOOKING IS FULL, PLEASE DO ENQUIRE TOMORROW'!!");
	else {

		if (fronttennis == -1)
			fronttennis = 0;
		reartennis++;
		strcpy(tennis[reartennis],name);
		tennistime++;

	}
	if(tennistime==1) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : TABLE TENNIS         |\n");
		printf("\t\t\t\t|\t TIME : 10.30 am - 11.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	} else if(tennistime==2) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : TABLE TENNIS         |\n");
		printf("\t\t\t\t|\t TIME : 11.30 am - 12.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	} else if(tennistime==3) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : TABLE TENNIS       |\n");
		printf("\t\t\t\t|\t TIME : 3.30 am - 4.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	}
	else if(tennistime==4) {
		printf("\n");

		printf("\t\t\t\t-------SCHEDULE COPY FOR %s--------\n",name);
		printf(" \t\t\t\t====================================\n");
		printf("\t\t\t\t|                                    |\n");
		printf("\t\t\t\t|\t GAME : TABLE TENNIS       |\n");
		printf("\t\t\t\t|\t TIME : 4.30 am - 5.30 am  |\n");
		printf(" \t\t\t\t====================================\n");
	}
}

//dequeue operations
void dequeuechess(){
	if (frontchess == -1){
		printf("\n");
		printf("\n\t\t\t\tQueue is Empty, NO BOOKINGS AS OF NOW!!\n");
	}
  else {
    printf("\n\t\t\t\tREMOVED %s BOOKING\n", chess[frontchess]);
    frontchess++;
    if (frontchess > rearchess)
      frontchess = rearchess = -1;
  }
}

void dequeuecarrom(){
	if (frontcarrom == -1){
		printf("\n");
		printf("\n\t\t\t\tQueue is Empty, NO BOOKINGS AS OF NOW!!\n");
	}
  else {
    printf("\n\t\t\t\tREMOVED %s BOOKING\n", carrom[frontcarrom]);
    frontcarrom++;
    if (frontcarrom > rearcarrom)
      frontcarrom = rearcarrom = -1;
  }
}

void dequeuecricket(){
	if (frontcricket == -1){
		printf("\n");
		printf("\n\t\t\t\tQueue is Empty, NO BOOKINGS AS OF NOW!!\n");
	}
  else {
    printf("\n\t\t\t\tREMOVED %s BOOKING\n", cricket[frontcricket]);
    frontcricket++;
    if (frontcricket > rearcricket)
      frontcricket = rearcricket = -1;
  }
}

void dequeuetennis(){
	if (fronttennis == -1){
		printf("\n");
		printf("\n\t\t\t\tQueue is Empty, NO BOOKINGS AS OF NOW!!\n");
	}
  else {
    printf("\n\t\t\t\tREMOVED %s BOOKING\n", tennis[fronttennis]);
    fronttennis++;
    if (fronttennis > reartennis)
      fronttennis = reartennis = -1;
  }
}
//display all queue details
void displaychess() {
  if (rearchess == -1)
    printf("\n \t\t\tQueue is Empty!!!\n");
  else {
    int i;
    printf("\n \t\t\tNAMES OF MEMBERS:\n");
    for (i = frontchess; i <= rearchess; i++)
      printf("  \t\t\t%s  \n", chess[i]);
  }
  printf("\n");
}
void displaycarrom() {
  if (rearcarrom == -1)
    printf("\n \t\t\tQueue is Empty!!!\n");
  else {
    int i;
    printf("\n \t\t\tNAMES OF MEMBERS:\n");
    for (i = frontcarrom; i <= rearcarrom; i++)
      printf("  \t\t\t%s  \n", carrom[i]);
  }
  printf("\n");
}
void displaycricket() {
  if (rearcricket == -1)
    printf("\n \t\t\tQueue is Empty!!!\n");
  else {
    int i;
    printf("\n \t\t\tNAMES OF MEMBERS:\n");
    for (i = frontcricket; i <= rearcricket; i++)
      printf("  \t\t\t%s  \n", cricket[i]);
  }
  printf("\n");
}
void displaytennis() {
	  if (reartennis == -1)
	    printf("\n \t\t\tQueue is Empty!!!\n");
	  else {
	    int i;
	    printf("\n \t\t\tNAMES OF MEMBERS:\n");
	    for (i = fronttennis; i <= reartennis; i++)
	      printf(" \t\t\t%s  \n", tennis[i]);
	  }
	  printf("\n");
}