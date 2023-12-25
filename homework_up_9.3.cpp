// homework_up_9.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// задача 3, урок 9 (умные указатели), тема "продвинутое программирование"
//Нужно создать упрощённый аналог std::unique_ptr.

//В шаблонном классе должны быть реализованы функции :

//Конструктор, принимающий сырой указатель.
//Перегружен оператор* для получения объекта.
//Запрещены оператор присваивания и конструктор копирования.
//Метод release, который освобождает владение и возвращает сырой указатель.
//Деструктор.


#include <iostream>
template <typename T>
class unique_ptr
{
public:
	
	unique_ptr() noexcept
	{
		ptr = nullptr;
	}

	unique_ptr(T* ptr)
	{
		this->ptr = ptr;

		std::cout << "Вызван конструктор" << std::endl;
	}
	
	~unique_ptr()
	{
		delete ptr;  // освободил память
		std::cout << "Вызван деструктор" << std::endl;
	}
	
	unique_ptr(const unique_ptr&) = delete;  // Здесь мы запретили конструктор копирования
	unique_ptr& operator=(const unique_ptr&) = delete;  // Здесь мы запретили оператор присваивания
	
	T& operator*()
	{
		return *ptr;
	};
	
	T* release() // эта функция освобождает владение и возвращает указатель 
	{
		T* tmp_ptr = ptr;  
		ptr = nullptr;
		return tmp_ptr;
	}
public:
	T* ptr;
};

int main()
{
	setlocale(LC_ALL, "ru");
	unique_ptr<int> object_uni1;
	std::cout << *object_uni1 << std::endl;
	unique_ptr<int> object_uni = new int(5);

	std::cout << *object_uni << std::endl;

	std::cout << object_uni.release() << std::endl;

	return 0;
}

