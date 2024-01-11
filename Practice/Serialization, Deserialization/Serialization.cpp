#include <iostream>
#include <vector>

int main()
{
	//데이터를 먼저 만들어보자
	int intData = 12345;
	//4바이트 2진수로 표현하면
	//00000000 00000000 00110000 00111001임
	//비트값으로 확인하면
	//00111001 00110000 00000000 00000000임
	//뒤부터 저장되는것을 알 수 있음
	//리틀엔디안 방식으로 데이터가 저장됨

	//Buffer는 데이터를 복사할 char 배열
	//어차피 int는 4byte니까 걍 char 4개짜리로 만들자
	std::vector<char> Buffer(4,0);

	//버퍼에 IntData를 복사하자
	memcpy_s(Buffer.data(), sizeof(intData), &intData, sizeof(intData));

	//결과를 보자
	//[57][48][0][0]가 저장됨 이게 Serialize의 가장 기본이라고 할 수있겠다.
	//즉 어떤 데이터를 바이트 단위 버퍼로 쪼개 관리하는것이 직렬화
	//비트값으로 확인하면
	//00111001 00110000 00000000 00000000

	//그럼 그럼 역직렬화는?
	//Buffer안에 데이터를 다시 int로 바꿔보자

	//데이터를 받을 놈
	int ReadData = 0;
	memcpy_s(&ReadData, sizeof(int), Buffer.data(), Buffer.size() * sizeof(char));
	
	//결과를 보자
	// *ReadData == 12345
	//알맞는 자료형에 알맞은 크기의 데이터를 복사하기만 하면, 해당 비트값을 해석하는건 자료형의 몫
	//잘 나옵니다


	//이번에는 스트링을 직렬화 해보자
	std::string StrData = "I am Hwang Seung-Min.";
	
	//string은 배열형이기 때문에 데이터의 크기가 정해져있는 자료형이 아니다
	//때문에 string의 길이를 알아야한다.
	//그래야 역직렬화를 할때, 길이에 맞춰 데이터를 담을 수 있다
	size_t StrDataLen = StrData.size();
	
	//그럼 두개의 데이터를 저장해야한다, 하나는 string의 길이, 다른 하나는 str데이터 그 자체
	//그만큼 이상의 버퍼 크기가 필요하겠죠? 대충 계산해서 넣읍시다
	Buffer.resize(sizeof(size_t) + StrDataLen * sizeof(char) + 1); // 맨뒤 \0를 생각하긴 했는데 흠...

	//버퍼에 StrDataLen값 먼저 복사하자
	memcpy_s(Buffer.data(), sizeof(size_t), &StrDataLen, sizeof(size_t));

	//StrData는 그 다음 위치부터 넣어야겠네요
	memcpy_s(Buffer.data() + sizeof(size_t), StrDataLen * sizeof(char), StrData.data(), StrDataLen * sizeof(char));

	//결과를 한번 봅시다
	//8바이트는 StrDataLen가, 그뒤 바이트들은 StrData로 잘 들어갔다.

	//이번엔다시 역직렬화
	std::string ReadStr;
	size_t ReadLen = 0;
	memcpy_s(&ReadLen, sizeof(size_t), Buffer.data(), sizeof(size_t));
	ReadStr.resize(ReadLen); //데이터를 읽어들일 메모리를 미리 확보
	memcpy_s(ReadStr.data(), ReadLen * sizeof(char), Buffer.data() + sizeof(ReadLen), ReadLen * sizeof(char));
	
	//결과를 보자
	//잘 나온다
	//데이터를 넣을 위치를 Offset으로 만들어 변수화하면 더 편하게 할 수 있다.
	//주소값이나 컴파일러 사양마다 자료형 크기가 달라질 수 있는 자료형들은 이런식의 직렬화가 사실 위험할 수 있다.
	//때문에 size_t를 직렬화 하는것도 안좋은습관 __int32 이런 자료형을 쓰는것이 안전할 수 있습니다.
}