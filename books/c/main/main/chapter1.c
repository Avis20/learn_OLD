#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

// print hello world
void hello_world(){
    printf("hello, world!\n");
}

// Считывает строку в s, возвращает ее длину
int get_line(char s[], int lim){
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar() ) != EOF && c != '\n'; i++ ){
        s[i] = c;
    }

    if ( c == '\n' ){
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

// Вывод таблицы температур по Фаренгейту и Цельсию от 20 до 300
void fat(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      // нижняя граница температур
    upper = 300;    // верняя граница температур
    step = 20;      // величина шага

    while ( fahr <= upper ){
        celsius = (5.0/9.0) * (fahr - 32.0); // c = (5/9)(f - 32)
        printf("%9.0f %6.2f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

// Вывод таблицы температур по Фаренгейту и Цельсию; v2
void fat3(){
    float fahr;

    for ( fahr = 0; fahr <= 300; fahr += 20 )
        printf("%3.0f %6.2f\n", fahr, (5.0/9.0)*(fahr-32));

    return 0;
}

// Вывод таблицы температур по Фаренгейту и Цельсию; v3
void fat5(){
    float fahr;

    for ( fahr = LOWER; fahr <= UPPER; fahr += STEP )
        printf("%3.0f %6.2f\n", fahr, (5.0/9.0)*(fahr-32));

    return 0;
}

// Вывод таблицы температур Цельсию по Фаренгейту
void celsius(){
    float fahr, celsius = 0;
    int lower, upper, step;

    lower = 0;      // нижняя граница температур
    upper = 100;    // верняя граница температур
    step = 20;      // величина шага

    while ( celsius <= upper ){
        fahr = (celsius * (9.0/5.0)) + 32;
        printf("%3.0f %6.2f\n", celsius, fahr);
        celsius += step;
    }
}

// копирование входного потока в выходной
void get_char(){
    char c;

    while ( (c = getchar()) != EOF )
        putchar(c);
}

// 1.1. Запустите программу "hello, world" на выполнение в вашей системе. Поэкспериментеруйте с ней, выбрасывая определенные фрагменты программы и наблюдая за сообщениями об ошибках, которые будут появлятся в связи с этим.
// done

// 1.2. Попытайтесь выяснить экспериментально, что происходит при передаче в функцию printf строки, содержащей управляющую последовательность \c, где c - некий символ, не входящий в вышеперечисленные комбинации.
// done

// 1.3. Модифицируйте программу преобразования температур так, чтобы она выводила заголовок над таблицей.
// done

void fat2(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      // нижняя граница температур
    upper = 300;    // верняя граница температур
    step = 20;      // величина шага

    printf("%s  %s\n", "Фаренгейт", "Цельсию");

    while ( fahr <= upper ){
        celsius = (5.0/9.0) * (fahr - 32.0); // c = (5/9)(f - 32)
        printf("%9.0f %6.2f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

// подсчет кол-ва символов в входном потоке
void count_chars(){
    long count = 0;
    while ( getchar() != EOF )
        ++count;
    printf("%ld", count);
}

// подсчет кол-ва строк в входном потоке
void count_str(){
    long count = 0;
    char c;

    while ( (c = getchar()) != EOF )
        if ( c == '\n' )
            ++count;

    printf("%ld\n", count);
}

// 1.4. Напишите программу для перевода температур по Цельсию в шкалу Фаренгейта и вывода соответствующей таблицы.

// 1.5. Доработайте программу преобразования температур так, чтобы она выводила таблицу в обратном порядке, т.е. от 300 градусов до нуля
// done

void fat4(){
    float fahr;

    for ( fahr = 300; fahr >= 0; fahr -= 20 )
        printf("%3.0f %6.2f\n", fahr, (5.0/9.0)*(fahr-32));

}

// 1.6. Проверьте, что выражение getchar() != EOF действительно равно 1 или 0;
// result: Если ввести символ то 1, если нажать ctrl+d то 0
// done

void check_eof(){
    printf("%d", ( getchar() != EOF ) );
}

// 1.7. Напишите программу вывода значения константы EOF
// result: -1
// done

void print_eof(){
    printf("%d", EOF);
}

// 1.8. Напишите программу для подчета пробелов, знаков табуляции и символов конца строки
// done

void count_spaces(){

    long count_spaces = 0, count_tabs = 0, count_endstr = 0;
    char c;

    while ( (c = getchar()) != EOF )
        if ( c == ' ' ){
            ++count_spaces;
        } else if ( c == '\t' ){
            ++count_tabs;
        } else if ( c == '\0' ){
            ++count_endstr;
        }

    printf("Кол-во пробелов = %ld; Кол-во табуляций = %ld; Кол-во символов конца строки = %ld\n",
           count_spaces, count_tabs, count_endstr);
}

// 1.9. Напишите программу для копирования входного потока в выходной с заменой строки состоящей из одного или нескольких пробелов, одним пробелом

// 1.10. Напишите программу для копирования входного потока в выходной с заменой знаков табуляции \t, символа знака назад (backspace) на \b, а косую четрту на \\.

// 1.12. Напишите программу для вывода входного потока по одному слову в строке

// 1.13. Напишите программу для вывода гистограммы длин слов во входном потоке. Построить гистограмму с горизонтальными рядами довольно легко, а вот с вертивальными столбцами труднее.

// 1.14. Напишите программу для вывода гистограммы частот, с которыми встречаются во входном потоке различные символы.

// 1.15. Перепешите программу преобразования температур, чтобы само преобразование выполнялось функцией

// 1.16. Доработайте главный модуль программы, определения самой длинной строки так, чтобы она выводила правильное значение для какой угодно длины строк входного потока, на сколько это позволяет текст

// 1.17. Напишите программу для вывода всех строк входного потока, имеющих длину более 80 символов

// 1.18. Напишите программу для удаления лишних пробелов и табуляций в хвосте каждой поступающей строки входного потка, которая бы также удаляла полностью пустые строки

// 1.19. Напишите функцию reverse(str), которая переписывает свой строковый аргумент str в обратном порядке.

// 1.20. Напишите программу detab, которая бы заменяла символы табуляции во входном потоке соответствующим кол-вом пробелов до следующий границы табуляции.

// 1.21. Напишите программу entab, которая заменяла пустые строки, состоящие из одних пробелов, строками, содержащими минимальное кол-во табуляций и дополнительных пробелов - так чтобы заполнять то же пространство. Используйте те же параметры табуляции, что и в программе detab. Если для заполнения места до следующей границы табуляции требуется один пробел или один символ табуляции, то что следует предпочесть?

// 1.22. Напишите программу для сворачивания слишком длинных строк входного потока в две или более короткие строки после последнего не пустого символа, встречающийся после n-ым столбцом длинной строки. Постарайтесь, чтобы ваша программа обрабатывала очень длинные строки корректно, а также удаляла лишние пробелы и табуляции перед указанным столбцом.

// 1.23. Напишите программу для удаления всех комментариев из программы на C. Позаботьтесь о корректной обработке символьных констант и строк в двойных кавычках. Вложенные комментарии в C не допускаются

// 1.24. Напишите программу для выполнения примитивной синтаксической проверки программ на C, такие как непарные круглые, квадратные и фигурные скобки. Незабудь о одинарных и двойных кавычках, управляющих символах и комментариях.




