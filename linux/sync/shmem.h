#define PERM 0666

// структура для записи в разделяемую память
typedef struct mem_msg {
    int segmet;
    char buf[100];
} Message;

// операции над семафором 1
// для ожидания партнера
// запирающее значение этого семафора 0
// разрешающее - 1

// дождаться когда семафор станет 1 и
// установить его в 0
static struct sembuf proc_wait[1] = {1, -1, 0};
// установить семафор в 1
// операция без условия
static struct sembuf proc_start[1] = {1, 1, 0};

// операции над семафором 0
// для блокировки ресурса
// запирающее значение этого семафора 1
// разрешающее - 0

// описание двух операций
// выполняются обе
static struct sembuf lock[2] = {
        0, 0, 0,  // дождаться когда семафор станет 0
        0, 1, 0  // увеличить значение на 1
};

// описание операции (выполняется одна)
// дождаться когда семафор станет 1 и
// установить его в 0
static struct sembuf unlock[1] = {0, -1, 0};