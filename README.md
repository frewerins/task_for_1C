Алгоритм заключается в следющем:
Будем хранить для каждой буквы дерево. Буква является корнем дерева, если какое-то слово начинается с нее. Каждый сын корня - это вторая буква в слове, следующем за тем словом, где корень - первая буква.
Например, если есть фраза "что такое слон, чистота - но не всегда" и корень дерева - ч, его сыновья - "а" и "о", сын а - о.
Если рассмотреть дерево с корнем "а", то оно будет пустым, так как никакое слово не начинается на букву а.
Таким образом наши деревья хранят все возможные ключи, которые могут храниться в тексте.
При получении ключа будем спускать по дереву до тех пор, пока не найдем сына для нужной буквы или пока не дойдем до конца ключа. Ответ на запрос O(n), где n - длина ключа.
При предпроцессинге проходимся по тексту один раз, для каждого слова добавляем первые его 5 букв в нужные деревья. Как это происходит: храним в векторе добавленные на предыдущем шаге указател на новые узлы, тогда наши текущие буквы должны быть их сыновьями. То есть третья буква в слове будет сыном второй буквы предыдущего слова.
Считаем, что нумерация слов начинается с единицы, если ключа нет в тексте - возвращаем единицу.
Используемый алфавит - английский.
