#ifndef TIME_H
#define TIME_H 

class CTime
{
public:
	CTime();
	CTime(int hour, int minute, int second = 0);
	CTime(int value);
	CTime(CTime& time);
	~CTime();
	CTime& operator=(CTime& time);//返回的是对象的引用形式

	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int getHour();
	int getMinute();
	int getSecond();  

	CTime operator+(CTime& time);

	///
	bool operator==(CTime& time);
	bool operator>(CTime& time);
	///
	CTime operator++();//前置的++
	CTime operator++(int);//后置++，这个int类型的参数只是为了区分，我们并不会使用这个参数，所以我们不需要形参的名字

	friend CTime addTime(CTime& time1, CTime& time2); 
	/*friend CTime operator+(CTime& time1, CTime& time2);*/

private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond; 
};

#endif