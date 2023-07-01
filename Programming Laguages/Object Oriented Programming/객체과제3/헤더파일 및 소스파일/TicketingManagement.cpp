#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Client.h" //헤더파일 Client.h를 불러온다.
#include "TicketingManagement.h"

using namespace std;


/*
 클래스 이름: TicketingManagement <Control 클래스>
 클래스 멤버 변수: clientList / clientNum / movieList / movieNum / systemLogInStatus / userID / userPW
 기능: TicketingManagement 클래스의 생성자로써의 기능을 수행한다.
	  생성자 호출을 통해 TicketingManagement의 멤버 변수 clientList / clientNum / movieList / movieNum은 인자로 전달된 값들로 초기화한다.
	  또한 객체 생성과 동시에 시스템 상의 로그인 여부를 나타내는 값은 false로, 프로그램 사용자에게 입력받아 저장할 ID 문자열, 패스워드 문자열, 영화이름 문자열들은 각각 NULL로 초기화한다. 

  매개변수 : Client** cList -> 회원들의 리스트
            int cNum -> 회원의 수
			Movie** mList -> 영화 리스트
	        int mNum -> 영화의 수

작성날짜: 2021/05/31
작성자: 박시홍
*/
TicketingManagement::TicketingManagement(Client** cList, int cNum, Movie** mList, int mNum)
{
	clientList = cList;
	clientNum = cNum;
	movieList = mList;
	movieNum = mNum; //예매 가능한 영화 숫자
	systemLogInStatus = false; //시스템 시작 시 로그인 상태는 false, 로그인이 완료되면 로그인 상태 true
	userID = NULL;
	userPW = NULL;
	userMovieName = NULL;
	

}


/*
   함수이름: showMenu
   기능: 프로그램 실행 메뉴를 출력하는 기능을 수행한다.
   매개변수: 없음
   반환값: 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void TicketingManagement::showMenu()
{

	cout << "메뉴: " << endl;
	cout << "1. 로그인" << endl;
	cout << "2. 영화 전체 조회 및 예매" << endl;
	cout << "3. 영화 검색 및 예매" << endl;
	cout << "4. 예매 영화 조회 " << endl;
	cout << "5. 종료하기" << endl;

}



/*
   함수이름: user_selectMenu
   기능: 프로그램 사용자에게 메뉴 선택 번호를 입력받고, 그 번호 값을 반환한다.
   매개변수: 없음
   반환값: 사용자의 메뉴 선택 번호

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
int TicketingManagement::user_selectMenu() 
{
	int choice;

	cin >> choice;

	return choice;
}



/*
   함수이름: user_inputID
   기능: 프로그램 사용자에게 ID를 입력받아 이를 맴버변수 userID에 저장한 후, userID를 반환한다.
   매개변수: 없음
   반환값: 사용자의 ID 입력값 =  userID

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* TicketingManagement::user_inputID()
{
	char Istr[100] = { 0, };
	
	cin >> Istr;
	userID = new char[strlen(Istr) + 5];
	strcpy(userID, Istr);
	
	return userID;
	
}



/*
   함수이름: user_inputPW
   기능: 프로그램 사용자에게 패스워드를 입력받아 이를 맴버변수 userPW에 저장한 후, userPW를 반환한다.
   매개변수: 없음
   반환값: 사용자의 패스워드 입력값 =  userPW

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* TicketingManagement::user_inputPW()
{

	char Pstr[100] = { 0, };

	cin >> Pstr;
	userPW = new char[strlen(Pstr) + 5];
	strcpy(userPW, Pstr);

	return userPW;

}



/*
   함수이름: user_selectMovie
   기능: 프로그램 사용자에게 예매할 영화번호를 입력받고, 그 번호 값을 반환한다.
   매개변수: 없음
   반환값: 사용자의 영화 선택 번호

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
int TicketingManagement::user_selectMovie() 
{
	int movieChoice;

	cin >> movieChoice;

	return movieChoice;
}



/*
   함수이름: user_inputMovieName
   기능: 프로그램 사용자에게 영화 제목을 입력받아 이를 맴버변수 userMovieName에 저장한 후, userMovieName을 반환한다.
   매개변수: 없음
   반환값: 사용자의 영화 제목 입력값 =  userMovieName

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* TicketingManagement::user_inputMovieName() 
{
	char Mstr[20] = { 0, };

	cin >> Mstr;
	userMovieName = new char[strlen(Mstr) + 5];
	strcpy(userMovieName, Mstr);
	return userMovieName;
}



/*
   함수이름: checkSystemLogInStatus
   기능: 멤버변수 systemLogInStatus 의 값을 반환한다.
   매개변수: 없음
   반환값: 시스템 상의 로그인 상태 여부 값 -> true: 현재 시스템 상 로그인이 된 상태
									     false: 현재 시스템 상 로그인이 되지 않은 상태
									
   작성날짜: 2021/05/31
   작성자: 박시홍
*/
bool TicketingManagement::checkSystemLogInStatus() 
{
	return systemLogInStatus;
}



/*
   함수이름: stopLogIn
   기능: 멤버변수 systemLogInStatus의 값을 true로 변경한다.
   매개변수: 없음
   반환값: 변경된 시스템 상의 로그인 상태 여부 값

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void TicketingManagement::stopLogIn()
{
	systemLogInStatus = true;
}



/*
   함수 이름: run
   기능: 사용자에게 프로그램 실행 메뉴 인터페이스를 보여주고, 사용자가 입력하는 번호에 따라서 다음과 같은 기능을 수행한다.

		(case 1) 로그인 기능 수행
		(case 2) 영화 전체 조회 및 예매 기능 수행 
		(case 3) 영화 검색 및 예매 기능 수행
		(case 4) 예매 영화 조회 기능 수행
		(case 5) 프로그램 종료 기능 수행 

   매개변수: 없음
   반환값: 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void TicketingManagement::run()
{
	int userSelectionMenu;
	bool loopStop = false;

	while (1)
	{

		this->showMenu();
		cout << "* 연산을 입력하시오: ";

		userSelectionMenu = this->user_selectMenu(); //사용자로부터 메뉴선택 번호를 입력받음



		switch (userSelectionMenu)
		{
		case 1: //로그인 기능 수행
		{
			this->LogIn();
			break;
		}
		case 2: //영화 전체 조회 및 예매 기능 수행
		{
			this->showListAndTicketing();
			break;
		}
		case 3: //염화 검색 및 예매 기능 수행
		{
			this->searchAndTicketing();
			break;
		}
		case 4: //예매 영화 조회 기능 수행
		{
			this->showAllTicketedMovie();
			break;
		}
		case 5: //프로그램 종료 기능 수행
		{
			this->exit();
			loopStop = true;
			break;
		}

		default:
			cout << "Illegal selection..." << endl<<endl<<endl;
		}

		if (loopStop == true)
			break;


	}
}



/*
   함수이름: LogIn
   기능: 사용자에게 ID, 패스워드를 입력받아 로그인하는 기능을 수행한다.
        <상세 기능>
		1. 사용자에게 ID, 패스워드를 입력받고, 이 입력값들에 매치되는 회원(Client) 객체를 찾는다.
		2. 회원 정보가 일치하는 객체가 있다면, 해당 객체의 로그인 상태를 true로 바꿔줌으로써 로그인 승인한 후, 로그인 성공 메세지를 출력한다.
		   또한 시스템 상 로그인이 성공했으므로 시스템 상의 로그인 상태도 true로 바꾸어줌으로써 더이상의 로그인을 차단하도록 한다.

		2 - <Alternatives> 만일 회원 정보가 일치하는 객체가 없다면, 로그인 실패 메세지를 출력한다.
   
   매개변수: 없음
   반환값: 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void TicketingManagement::LogIn()
{

	if (this->checkSystemLogInStatus() == false) //시스템 상 로그인이 한번도 성공되지 않았을 경우에 실행
	{
		char IDstr[100] = { 0, }; //입력받은 ID를 저장할 문자배열 선언
		char PWstr[100] = { 0, }; //입력받은 패스워드를 저장할 문자배열 선언 

		cout << " - ID 입력하시오: ";
		strcpy(IDstr, this->user_inputID()); //사용자로부터 ID를 입력받아 IDstr에 복사

		cout << " - 패스워드 입력하시오: ";
		strcpy(PWstr, this->user_inputPW()); //사용자로부터 패스워드를 입력받아 PWstr에 복사


		for (int i = 0; i < clientNum; i++)
		{
			if ((strcmp(IDstr, clientList[i]->getClientID()) == 0) && (strcmp(PWstr, clientList[i]->getClientPW()) == 0)) //입력받은 ID, PW 문자열과 둘 다 일치하는 회원 객체가 있다면
			{
				clientList[i]->changeLogInStatus(); //ID, 패스워드 정보 일치하는 회원 객체의 로그인 승인을 명령
				cout << " -> 로그인에 성공했습니다.";
				cout << endl << endl << endl;

				this->stopLogIn(); //시스템 상 한번 로그인이 성공되었으므로, 추가적인 로그인을 하지 못하도록 차단하게 하기 위함

				return;
			}

		}

		for (int i = 0; i < clientNum; i++)
		{
			if ((strcmp(IDstr, clientList[i]->getClientID()) != 0) || (strcmp(PWstr, clientList[i]->getClientPW()) != 0)) //입력받은 ID, PW 문자열과 둘 다 일치하는 회원 객체가 없다면
			{
				cout << " -> 로그인에 실패했습니다.";
				cout << endl << endl << endl;

				return;
			}
		}
	}

	if (this->checkSystemLogInStatus() == true) //시스템 상 로그인이 한번이라도 성공했을 경우 실행
	{
		cout << "이미 로그인 되어있습니다." << endl << endl << endl; 
		return;
	}


}



/*
   함수이름: showListAndTicketing
   기능: 사용자에게 영화 전체 목록을 보여주고, 이 중에서 예매할 영화의 번호를 입력받아 해당 영화의 예매를 진행한다. 또한 예매된 영화는 회원의 예매 리스트에 추가시킨다.
		<상세 기능>
		1. 로그인이 되지 않은 상태에서 이 기능은 실행할 수 없다.
		2. 로그인 승인된 회원 객체를 찾아 영화 전체 목록을 보여준다.
		3. 사용자는 console창에 출력된 영화 전체 목록 중 예매할 영화 번호를 입력한다.
		4. 입력받은 영화 번호가 적합하다면, 로그인 승인된 회원 객체의 예매 리스트에 해당 번호의 영화를 추가한다. 그리고 영화 이름을 포함한 예매 완료 메세지를 출력한다.
		4 - <Alternatives> 만일 입력받은 영화 번호가 적합하지 않다면 예매 실패 메세지를 출력한다.
		
   매개변수: 없음
   반환값: 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void TicketingManagement::showListAndTicketing()
{
	int userMovieSelectionNum = 0; //영화 번호를 입력받을 수 있는 변수 선언
	

	if (this->checkSystemLogInStatus() == false) //만약 시스템상 로그인이 되지 않은 상태라면
	{
		cout << "로그인 후 이용 가능한 영역입니다";
		cout << endl << endl << endl;
	}



	for (int i = 0; i < clientNum; i++)
	{

		if (clientList[i]->getLogInStatus() == true) //로그인 승인된 계정을 찾기
		{
			while (1)
			{
				for (int j = 0; j < movieNum; j++)
				{
					cout << ' ' << j + 1 << ") ";
					cout << movieList[j]->getMovieInfo(); //영화 객체들의 영화 정보들을 반환받아 출력한다.  
					cout << endl; 
				}

				cout << "* 예매할 영화를 선택하시오 : ";

				userMovieSelectionNum = this->user_selectMovie(); //사용자로부터 예매할 영화 번호를 입력받음

				if (userMovieSelectionNum > 0 && userMovieSelectionNum < movieNum + 1) //입력 받은 영화 번호가 적합한 경우
				{

					clientList[i]->addMovie(movieList[userMovieSelectionNum - 1]); //실제 예매할 영화 객체는 movieList[userSelectionNum-1]에 저장되어있으므로, 여기에 접근해 해당 영화를 로그인된 회원의 예매 리스트에 추가한다. 
					cout << " -> 영화 " << '"' << movieList[userMovieSelectionNum - 1]->getMovieName() << '"' << " 예매되었습니다.";
					cout << endl << endl << endl;

					break;
				}
				else
				{
					cout << "영화 번호를 올바르게 선택하십시오.";
					cout << endl << endl << endl;
	
				}
			}
			
		}

	}
}




/*
   함수이름: searchAndTicketing
   기능: 예매할 영화의 제목을 사용자로부터 입력받아 제목과 일치하는 영화를 조회해서 출력한다. 
        그 후 검색결과로 나오는 영화들 중 예매할 영화의 번호를 입력받아 해당 영화의 예매를 진행한다. 또한 예매된 영화는 회원의 예매 리스트에 추가시킨다.
  
		<상세 기능>
		1. 로그인이 되지 않은 상태에서 이 기능은 실행할 수 없다.
		2. 로그인 승인된 회원 객체를 찾아 영화 제목을 입력할 수 있는 필드를 출력한다.
		3. 사용자는 console창에 예매할 영화 제목을 입력한다.
		4. 입력받은 영화 제목이 멤버변수 movieList에 있는 영화제목들과 일치하는 지 확인한다.
		5. 일치하는 영화가 없는 경우 해당 영화 없음을 출력한다.
		6. 일치하는 영화가 있다면 일치하는 영화의 정보들을 console창에 출력하고, 일치한 영화들을 tempArr[4]배열에 담아 인덱스 제일 앞부분부터 순차적으로 일치하는 영화 객체가 자리하도록 정렬하였다.
		7. 사용자는 console창에 출력된 검색 결과 중 예매할 영화 번호를 입력한다.
		8. 입력받은 영화 번호가 적합하다면, 로그인 승인된 회원 객체의 예매 리스트에 해당 번호의 영화를 추가한다. 그리고 영화 이름을 포함한 예매 완료 메세지를 출력한다.
		8 - <Alternatives> 만일 입력받은 영화 번호가 적합하지 않다면 예매 실패 메세지를 출력한다.

   매개변수: 없음
   반환값: 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void TicketingManagement::searchAndTicketing()
{
	char movieSearchArr[20] = { 0, }; //입력받은 영화제목을 저장할 문자배열 선언
	int searchIdx = 0; //입력받은 영화 제목과 일치하는 영화가 있는 지 확인하기 위한 인덱스 번호 -> searchIdx와 movieNum(영화 개수)이 같다면 일치하는 영화 없음
	int movieIdx = 0; //영화 제목 일치하면 번호로 출력될 idx
	int userMovieSelectionNum = 0; //영화 번호를 입력받을 수 있는 변수 선언
	Movie* tempArr[4]; //임시로 담을 영화 객체 포인터 배열


	for (int i = 0; i < 4; i++)
	{
		tempArr[i] = NULL; //임시로 담을 영화 객체 포인터 배열 요소들을 NULL로 초기화
	}

	if (this->checkSystemLogInStatus() == false) //만약 시스템상 로그인이 되지 않은 상태라면
	{
		cout << "로그인 후 이용 가능한 영역입니다";
		cout << endl << endl << endl;
	}

	for (int i = 0; i < clientNum; i++)
	{

		if (clientList[i]->getLogInStatus() == true) //로그인 승인된 계정을 찾기
		{
			cout << "* 검색할 제목을 입력하시오: ";

			strcpy(movieSearchArr, user_inputMovieName()); //사용자로부터 예매할 영화 제목을 입력받아 movieSearchArr에 복사

			for (int j = 0; j < movieNum; j++)
			{
				if (strcmp(movieSearchArr, movieList[j]->getMovieName()) != 0) //입력받은 영화 제목이 리스트에 있는 영화 제목인지 조사, 틀리다면 다음 인덱스 영화이름과 비교
				{
					searchIdx++; // 입력받은 영화 제목과 일치하는 영화가 없다면 1씩 증가시킴으로써 searchIdx와 movieNum(영화 개수)이 같아지면 일치하는 영화가 리스트에 없다는 것임
				}

			}

			if (searchIdx == movieNum) //리스트 끝까지 조사했는데 영화 제목이 일치하는 게 없다면 해당 영화 없음 출력
			{
				cout << " -> 해당 영화가 없습니다.";
				cout << endl << endl << endl;
				return;
			}

			for (int j = 0; j < movieNum; j++)
			{
				if ((strcmp(movieSearchArr, movieList[j]->getMovieName()) == 0)) //입력받은 영화 제목과 일치하는 영화가 있다면
				{
					cout << ' ' << movieIdx + 1 << ") ";
					cout << movieList[j]->getMovieInfo() << endl; //일치하는 영화의 정보를 필드에 출력

					tempArr[j] = movieList[j]; //일치하는 영화들을 tempArr에 담음
					movieIdx++;  //결국 movieIdx는 일치하는 영화의 개수임
				}

			}

			for (int i = 0; i < movieNum - 1; i++) //tempArr 배열에 있는 영화 리스트를 정렬 -> 배열에 들어있는 배열 요소가 NULL이면 SWAP을 구현함으로써 인덱스 제일 앞부분부터 순차적으로 일치하는 영화 객체가 자리하도록 정렬하였음
			{
				for (int j = 0; j < movieNum - 1; j++)
				{
					if (tempArr[j] == NULL)
					{
						Movie* tempMovie = tempArr[j];
						tempArr[j] = tempArr[j + 1];
						tempArr[j + 1] = tempMovie;
					}

				}
			}

			cout << "* 예매할 영화를 선택하시오: ";
			
			userMovieSelectionNum = this->user_selectMovie(); //사용자로부터 예매할 영화 번호를 입력받음

			if (userMovieSelectionNum > 0 && userMovieSelectionNum < movieIdx + 1) //입력 받은 영화 번호가 적합한 경우
			{
				clientList[i]->addMovie(tempArr[userMovieSelectionNum - 1]); //실제 예매할 영화 객체는 tempArr[userSelectionNum-1]에 저장되어있으므로, 여기에 접근해 해당 영화를 로그인된 회원의 예매 리스트에 추가한다.
				cout << " -> 영화 " << '"' << tempArr[userMovieSelectionNum - 1]->getMovieName() << '"' << " 예매되었습니다.";
				cout << endl << endl << endl;
			}

			else
			{
				cout << "영화 번호를 올바르게 선택하십시오.";
				cout << endl << endl << endl;

			}
		}
	}
}




/*
   함수이름: showAllTicketedMovie
   기능: 사용자에게 예매 영화 조회 서비스를 제공하는 기능을 수행한다.
		<상세 기능>
		1. 로그인이 되지 않은 상태에서 이 기능은 실행할 수 없다.
		2. 로그인 승인된 회원 객체를 찾아 해당 회원의 예매 내역을 출력한다.
		
   매개변수: 없음
   반환값: 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void TicketingManagement::showAllTicketedMovie()
{
	if (this->checkSystemLogInStatus() == false) //만약 시스템상 로그인이 되지 않은 상태라면
	{
		cout << "로그인 후 이용 가능한 영역입니다";
		cout << endl << endl << endl;
	}

	for (int i = 0; i < clientNum; i++)
	{

		if (clientList[i]->getLogInStatus() == true) //로그인 승인된 계정을 찾기
		{

			clientList[i]->showMyMovieList(); //로그인 승인된 회원의 영화 예매 리스트를 출력한다.
			cout << endl << endl << endl;
		}
	}
}



/*
   함수이름: exit
   기능: 프로그램 종료 기능을 수행한다.
		<상세 기능>
		1. 로그인 되어있던 회원 객체를 찾아 로그아웃시킨다.
		2. 프로그램 종료 메세지를 출력한다.

   매개변수: 없음
   반환값: 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void TicketingManagement::exit()
{
	for (int i = 0; i < clientNum; i++)
	{

		if (clientList[i]->getLogInStatus() == true)
		{

			clientList[i]->changeLogInStatus();
			
		}
	}
	cout << " -> 종료합니다." << endl;
}



/*
   함수이름: 클래스 TicketingManagement의 소멸자
   기능 : TicketingManagement 객체가 소멸될 때 호출된다.
		 동적할당한 userID, userPW, userMovieName 메모리들을 해제시켜준다.
   매개변수 : 없음
   반환값 : 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
TicketingManagement::~TicketingManagement()
{
	delete[]userID;
	delete[] userPW;
	delete[] userMovieName;
}
