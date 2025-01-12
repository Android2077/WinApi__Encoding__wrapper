#include <iostream>
#include <string>


int main()
{

	//Данный класс сожержит методы преобразования между кодировками UTF-16(wstring), UTF-8 и действующей национальной одобайтовой кодировкой испольуя функции WinApi.  
        //Внутри используется включение windows.h - поэтому в свойствах проекта необходимо дополнительно подключить - user32.lib и gdi32.lib(для My_Quasi_Unicode_Сonsole_)  
	
	WinApi__Encoding__class WinApi__Encoding__class_;
		
	//Методы:
	//-My_Quasi_Unicode_Сonsole_                      - Это очень простое вспомгательно WinApi окно - чтобы в него можно было выводить простой любой юникодный текст в кодировке UTF-16(wstring) и UTF-8.
	//-from_UTF16wstring_to_UTF8                      - Функция конвертирует строку std::wstring в кодировке UTF-16 в строку std::string -> в кодировке UTF-8.
	//-from_UTF8_to_UTF16wstring                      - ункция конвертирует строку std::string в кодировке UTF-8 в строку std::wstring  -> в кодировке UTF-16.
	//-from_CP_ACP_to_UTF16wstring                    - Функция конвертирует строку std::string в национальной однобайтовой кодировке действующей на данный момент в системе -> в строку std::wstring в кодировке UTF-16.
	//-from_CP_ACP_to_UTF8                            - Функция конвертирует строку std::string в национальной однобайтовой кодировке действующей на данный момент в системе -> в строку std::wstring в кодировке UTF-8.



	WinApi__Encoding__class::result_flag result;


	//-------------------------------------------------------------------------------0-My_Quasi_Unicode_Сonsole_:Начало----------------------------------------------------------------------

	//Это очень простое вспомгательно WinApi окно - чтобы в него можно было выводить простой любой юникодный текст в кодировке UTF-16(wstring) и UTF-8.
	//Просто чтобы не мучится с выводом юникода в стандарнут консоль. Так как это просто быстро созданное окошечко, но никакой обработки ошибок нет. Упадет, да и хрен с ним, если такое случится, то максимум из за нехватки памяти, а так не должно в принципе.

	WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_;      //Обьект класса "Юникодного квази-коснольного окна"

	//Методы:
	//-create_Window
	//-cout
	//-endl
	//-free
	//-free
	//-shrink_to_fit__free



	//----------------------------------------------------------------------------------------cout:Начало---------------------------------------------------------------------------------

	//Инициализирует и создает WinApi окно. ДОЛЖНО быть вызвано один раз, перед всеми остальными методами.

	WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.create_Window();

	//----------------------------------------------------------------------------------------cout:Конец---------------------------------------------------------------------------------





	//----------------------------------------------------------------------------------------cout:Начало---------------------------------------------------------------------------------

	//Выводит в окне текст в строке std::wstring или std::string:
	//Кодировка в строке std::wstring ДОЛЖНА быть UTF-16
	//Кодировка в строке std::string ДОЛЖНА быть UTF-8.


	std::wstring wstring_UTF16            = L"Это кодировка UTF16(wstring) 东";
	std::string string_UTF8               = u8"Это кодировка UTF8 东";

	WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.cout(wstring_UTF16);
	WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.endl();
	WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.cout(string_UTF8);
	WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.endl();

	//----------------------------------------------------------------------------------------cout:Конец---------------------------------------------------------------------------------




	//----------------------------------------------------------------------------------------endl:Начало---------------------------------------------------------------------------------

	//Добавляет перенос строки, аналогично "std::endl"

	//WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.endl();

	//----------------------------------------------------------------------------------------endl:Конец---------------------------------------------------------------------------------





	//----------------------------------------------------------------------------------------free:Начало---------------------------------------------------------------------------------

	//Удаляет весь текст из буффера текста, который на данный момент отображается в окне.

	WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.free();


	//----------------------------------------------------------------------------------------free:Конец---------------------------------------------------------------------------------


	//----------------------------------------------------------------------------------------shrink_to_fit__free:Начало---------------------------------------------------------------------------------

	//Тоже самое, что и free, но с попыткой освободить полностьб память под буффер текста в окне.


	//WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.shrink_to_fit__free();

	//----------------------------------------------------------------------------------------shrink_to_fit__free:Конец---------------------------------------------------------------------------------





	//-------------------------------------------------------------------------------0-My_Quasi_Unicode_Сonsole_:Конец----------------------------------------------------------------------








	//-------------------------------------------------------------------------------1-from_UTF16wstring_to_UTF8:Начало----------------------------------------------------------------------

	//Функция конвертирует строку std::wstring в кодировке UTF-16 в строку std::string -> в кодировке UTF-8.


	std::wstring wstring_UTF16_1 = L"Привет_东_UTF8_1";

	//-------------------------------------------------------------

	const wchar_t* pointer_to_text_1    = wstring_UTF16_1.c_str();                        //Указатель на текст в кодировке UTF-16(wstring), который нужно конвертировать в UTF-8.

	const size_t size_text_1            = wstring_UTF16_1.size();                          //Размер в символах wchar_t по указателю на текст в кодировке UTF-16(wstring), который нужно конвертировать в UTF-8.

	std::string string_UTF8_1;                                                            //Сюда функция добавит в конец результат в виде сконвертированных данных. Все данные, которые был до момента вызова сохранятся и в конец добавляется результат.

	//-------------------------------------------------------------



	//-------------------------------------------------------------
	//string_UTF8_1.resize(0);   //Так как фугкция Доабвляет результат в конец передаваемой строки, то, если нужно, чтобы результат был записан с самоо начала, то предварительно его нужно обнулить.
	
	result = WinApi__Encoding__class_.from_UTF16wstring_to_UTF8(pointer_to_text_1, size_text_1, string_UTF8_1);

	if (result != WinApi__Encoding__class::result_flag::OK)
	{
		std::cout << "error_1:" << WinApi__Encoding__class_.get__ErrorName() << std::endl;

		return -1;
	}
	else
	{
		WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.cout(string_UTF8_1);     //Выводим сконвертированную строку в окно для проверки.
	}
	//-------------------------------------------------------------
	

	//-------------------------------------------------------------------------------1-from_UTF16wstring_to_UTF8:Конец----------------------------------------------------------------------



	//-------------------------------------------------------------------------------2-from_UTF8_to_UTF16wstring:Начало----------------------------------------------------------------------

	//Функция конвертирует строку std::string в кодировке UTF-8 в строку std::wstring  -> в кодировке UTF-16.


	std::string string_UTF8_2 = u8"Привет_东_UTF16_2";

	//-------------------------------------------------------------

	const char  * pointer_to_text_2      = string_UTF8_2.c_str();                          //Указатель на текст в кодировке UTF-8, который нужно конвертировать в UTF-8(wstring).

	const size_t size_text_2             = string_UTF8_2.size();                           //Размер в символах char по указателю на текст в кодировке UTF-8, который нужно конвертировать в UTF-8(wstring).

	std::wstring wstring_UTF16_2;                                                          //Сюда функция добавит в конец результат в виде сконвертированных данных. Все данные, которые был до момента вызова сохранятся и в конец добавляется результат.

	//-------------------------------------------------------------


	//-------------------------------------------------------------
	//wstring_UTF16_2.resize(0);   //Так как фугкция Доабвляет результат в конец передаваемой строки, то, если нужно, чтобы результат был записан с самоо начала, то предварительно его нужно обнулить.
	
	result = WinApi__Encoding__class_.from_UTF8_to_UTF16wstring(pointer_to_text_2, size_text_2, wstring_UTF16_2);

	if (result != WinApi__Encoding__class::result_flag::OK)
	{
		std::cout << "error_2:" << WinApi__Encoding__class_.get__ErrorName() << std::endl;

		return -1;
	}
	else
	{
		WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.endl();
		WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.cout(wstring_UTF16_2);     //Выводим сконвертированную строку в окно для проверки.
	}
	//-------------------------------------------------------------


	//-------------------------------------------------------------------------------2-from_UTF8_to_UTF16wstring:Конец----------------------------------------------------------------------



	//-------------------------------------------------------------------------------3-from_CP_ACP_to_UTF16wstring:Начало----------------------------------------------------------------------

	//Функция конвертирует строку std::string в национальной однобайтовой кодировке действующей на данный момент в системе -> в строку std::wstring в кодировке UTF-16.


	std::string string_CP_ACP_3 = "Привет_东_CP_ACP_3";

	//-------------------------------------------------------------

	const char* pointer_to_text_3     = string_CP_ACP_3.c_str();                         //Указатель на текст в кодировке в Национальной действующей кодировке, который нужно конвертировать в UTF-16(wstring).

	const size_t size_text_3          = string_CP_ACP_3.size();                          //Размер в символах char по указателю на текст в Национальной действующей кодировке, который нужно конвертировать в UTF-16(wstring).

	std::wstring wstring_UTF16_3;                                                        //Сюда функция добавит в конец результат в виде сконвертированных данных. Все данные, которые был до момента вызова сохранятся и в конец добавляется результат.

	//-------------------------------------------------------------



	//-------------------------------------------------------------
	//wstring_UTF16_3.resize(0);   //Так как фугкция Доабвляет результат в конец передаваемой строки, то, если нужно, чтобы результат был записан с самоо начала, то предварительно его нужно обнулить.
	
	result = WinApi__Encoding__class_.from_CP_ACP_to_UTF16wstring(pointer_to_text_3, size_text_3, wstring_UTF16_3);

	if (result != WinApi__Encoding__class::result_flag::OK)
	{
		std::cout << "error_4:" << WinApi__Encoding__class_.get__ErrorName() << std::endl;

		return -1;
	}
	else
	{
		WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.endl();
		WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.cout(wstring_UTF16_3);     //Выводим сконвертированную строку в окно для проверки.
	}
	//-------------------------------------------------------------




	//-------------------------------------------------------------------------------3-from_CP_ACP_to_UTF16wstring:Конец----------------------------------------------------------------------




	//-------------------------------------------------------------------------------4-from_CP_ACP_to_UTF8:Начало----------------------------------------------------------------------

	//Функция конвертирует строку std::string в национальной однобайтовой кодировке действующей на данный момент в системе -> в строку std::wstring в кодировке UTF-8.


	std::string string_CP_ACP_4 = "Привет_东_CP_ACP_4";

	//-------------------------------------------------------------

	const char* pointer_to_text_4           = string_CP_ACP_4.c_str();                         //Указатель на текст в Национальной действующей кодировке, который нужно конвертировать в UTF-8.

	const size_t size_text_4                = string_CP_ACP_4.size();                          //Размер в символах char по указателю на текст в Национальной действующей кодировке, который нужно конвертировать в UTF-8.

	std::string string_UTF8_4;                                                                 //Сюда функция добавит в конец результат в виде сконвертированных данных. Все данные, которые был до момента вызова сохранятся и в конец добавляется результат.

	//-------------------------------------------------------------



	//-------------------------------------------------------------
	//string_UTF8_4.resize(0);   //Так как фугкция Доабвляет результат в конец передаваемой строки, то, если нужно, чтобы результат был записан с самоо начала, то предварительно его нужно обнулить.
	
	result = WinApi__Encoding__class_.from_CP_ACP_to_UTF8(pointer_to_text_4, size_text_4, string_UTF8_4);

	if (result != WinApi__Encoding__class::result_flag::OK)
	{
		std::cout << "error_4:" << WinApi__Encoding__class_.get__ErrorName() << std::endl;

		return -1;
	}
	else
	{
		WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.endl();
		WinApi__Encoding__class_.My_Quasi_Unicode_Сonsole_.cout(string_UTF8_4);     //Выводим сконвертированную строку в окно для проверки.
	}
	//-------------------------------------------------------------


	//-------------------------------------------------------------------------------4-from_CP_ACP_to_UTF8:Конец----------------------------------------------------------------------


}
