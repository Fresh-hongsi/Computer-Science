#ifndef __MOVIE_H__
#define __MOVIE_H__


/*
Ŭ���� �̸� : Movie <Entity Ŭ����>
Ŭ���� ��� ����:  movieName / movieDirector / movieGenre / movieInfoStr 

��� : ��ȭ�� ���� ������ ���� ����� ������

	 < private ����Լ� >
	 1. char* getMovieDirector()
	   -> ��ȭ ���� �̸� ������ ��ȯ�Ѵ�.
	
	 2. char* getMovieGenre()
	   -> ��ȭ�� �帣 ������ ��ȯ�Ѵ�.

	< public ����Լ� >
	 1. Movie(const char* mName, const char* mDirector, const char* mGenre)
	   -> ��ȭ�� ����, ��ȭ ����, ��ȭ �帣 ������ �޾� ��ü�� �����Ѵ�. ��ȭ ������ ��ȯ�� ���ڿ��� ��ü ������ ���ÿ� ������ ������ NULL�� �ʱ�ȭ�Ѵ�.
	 
	 2. char* getMovieName()
	   -> ��ȭ�� ���� ������ ��ȯ�Ѵ�.
	 
	 3. char* getMovieInfo()
	   -> ��ȭ ����, ��ȭ ����, ��ȭ �帣 ������ ������ ���ڿ��� ��ȯ�Ѵ�.
	 
	 4. ~Movie()
	   -> �Ҹ��ڸ� ���� �����Ҵ��� �޸𸮸� �����Ѵ�.

�ۼ���¥ : 2021/05/31
�ۼ��� : �ڽ�ȫ
*/
class Movie
{
private:
	char* movieName;
	char* movieDirector;
	char* movieGenre;
	char* movieInfoStr; //��ȭ ������ ��ȯ�� ���ڿ�
	

	char* getMovieDirector();

	char* getMovieGenre();


public:
	Movie(const char* mName, const char* mDirector, const char* mGenre);

	char* getMovieName();

	char* getMovieInfo(); //��ȭ ���� ���ڿ� ��ȯ �Լ�

	~Movie();
};
#endif