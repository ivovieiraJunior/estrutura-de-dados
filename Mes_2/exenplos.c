1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305
306
307
308
309
310
311
312
313
314
315
316
317
318
319
320
321
322
323
324
325
326
327
328
329
330
331
332
333
334
335
336
337
338
339
340
341
342
343
344
345
346
347
348
349
350
351
352
353
354
355
356
357
358
359
360
361
362
363
364
365
366
	
#include <stdio.h>
#include <stdlib.h>
 
enum boolean
{
    true = 1, false = 0
};
typedef enum boolean bool;
 
 
typedef struct Node{
    int info;
    struct Node *proximo;
}No;
 
No *primeiro = NULL;
 
void inserirPrimeiro(int valor);//Insere um nó na primeira posição
 
void inserirUltimo(int valor);//Insere um nó na ultina posição
 
void imprimir();//Imprime os valores de todos os nós
 
void limpar();//Remove todos os nós da Lista
 
void removerValor(int valor);//Remove todos os nós com info = valor
 
void removerPrimeiro();//Remove o primeiro nó da Lista
 
void removerUltimo();//Remove o ultimo nó da Lista
 
void removerPosicao(int i);//Remove o nó da posição i
 
int tamanho();//Retona o numeros de nós da Lista
 
void inserirPosicao(int i, int valor);//Insere um nó com info = valor na posição i
 
bool estaOrdenada();//Retorna se a lista está em ordem crescente
 
int multiplos(int valor);//Retorna o numero de nós que são multiplos de valor
 
int removerPares();//Remove todos os nós pares, e retorna o número de nós excluidos
 
int main()
{
    //ALGUNS TESTES JÁ FEITOS.
    inserirPrimeiro(60);
    inserirPrimeiro(50);
    inserirPrimeiro(40);
    inserirPrimeiro(30);
    inserirPrimeiro(20);
    inserirPrimeiro(10);
    removerPares();
    imprimir();
    int x = 3;
    printf("Sao %d multiplos de %d.", multiplos(x), x);
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    removerPosicao(3);
    printf("\n");
    imprimir();
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    inserirPosicao(3,99);
    printf("\n");
    imprimir();
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    inserirUltimo(22);
    printf("\n");
    imprimir();
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    return 0;
}
 
void inserirPrimeiro(int valor)
{
    No *no = (No*) malloc (sizeof(No));
    no->info = valor;
    no->proximo = primeiro;
    primeiro = no;
}
 
void imprimir()//Imprime os valores de todos os nós
{
    if (primeiro == NULL)
    {
        printf("A lista esta vazia!");
        return;
    }
    No *no = primeiro;
    while (no != NULL)
    {
        printf("%d ", no->info);
        no = no->proximo;
    }
}
 
void limpar()//Remove todos os nós da Lista
{
    No *no = primeiro, *aux;
    while (no != NULL)
    {
        aux = no;
        no = no->proximo;
        free (aux);
    }
    primeiro = NULL;
}
 
void removerValor(int valor)//Remove todos os nós com info = valor
{
    if (primeiro != NULL)
    {
        No *no = primeiro, *aux = no->proximo, *anterior = NULL;
        while (aux != NULL)
        {
            if (no == primeiro)
            {
                if (no->info == valor)
                {
                    primeiro = aux;
                    free(no);
                    no = primeiro;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
            else
            {
                if (no->info == valor)
                {
                    anterior->proximo = aux;
                    free(no);
                    no = aux;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
        }
        //condição para o último nó
        if (no->info == valor)
        {
            if (tamanho > 1)
            {
                anterior->proximo = NULL;
                free(no);
            }
            else
            {
                free(no);
                primeiro = NULL;
            }
        }
    }
}
 
void removerPrimeiro()//Remove o primeiro nó da Lista
{
    if (primeiro != NULL)
    {
        No *no = primeiro;
        primeiro = no->proximo;
        free(no);
    }
}
 
void removerUltimo()//Remove o ultimo nó da Lista
{
    if (primeiro != NULL)
    {
        No *no = primeiro, *aux = no->proximo;
        while(aux->proximo != NULL)
        {
            no = no->proximo;
            aux = aux->proximo;
        }
        free(aux);
        no->proximo = NULL;
    }
}
 
void removerPosicao(int i)//Remove o nó da posição i
{
    if (i < 0)
        return;
    if ((primeiro != NULL) && (tamanho() >= i))
    {
        No *no = primeiro, *aux, *anterior;
        int cont = 0;//para contagem da posição a partir de 0
        while (cont < i)
        {
            anterior = no;
            no = no->proximo;
            cont++;
        }
        aux = no->proximo;
        free(no);
        anterior->proximo = aux;
    }
}
 
int tamanho()//Retona o numeros de nós da Lista
{
    int cont = 0;
    No *no = primeiro;
    while (no != NULL)
    {
        no = no->proximo;
        cont++;
    }
    return cont;
}
 
void inserirPosicao(int i, int valor)//Insere um nó com info = valor na posição i
{
    if (i < 0)
        return;
    if (i == 0)
    {
        inserirPrimeiro(valor);
        return;
    }
    if (tamanho() >= i)
    {
        No *no = primeiro, *aux, *novo;
        novo = (No*) malloc (sizeof(No));
        novo->info = valor;
        int cont = 0;//para contagem da posição a partir de 0
        while (cont < i-1)//i-1 para parar uma posição antes de i, para fazer a inserção na posição certa
        {
            no = no->proximo;
            cont++;
        }
        aux = no->proximo;
        no->proximo = novo;
        novo->proximo = aux;
    }
}
 
void inserirUltimo(int valor)//Insere um nó na ultina posição
{
    if (primeiro == NULL)
    {
        inserirPrimeiro(valor);
        return;
    }
    No *no = primeiro, *novo;
    while (no->proximo != NULL)
    {
        no = no->proximo;
    }
    novo = (No*) malloc (sizeof(No));
    novo->info = valor;
    novo->proximo = NULL;
    no->proximo = novo;
}
 
bool estaOrdenada()//Retorna se a lista está em ordem crescente
{
    if (primeiro != NULL)
    {
        No *no = primeiro;
        while (no->proximo != NULL)
        {
            if (no->info > no->proximo->info)
                return false;
            no = no->proximo;
        }
    }
    return true;
}
 
int multiplos(int valor)//Retorna o numero de nós que são multiplos de valor
{
    int cont = 0;
    if (primeiro != NULL)
    {
        No *no = primeiro;
        while (no != NULL)
        {
            if ((no->info % valor) == 0)
                cont++;
            no = no->proximo;
        }
    }
    return cont;
}
 
int removerPares()//Remove todos os nós pares, e retorna o número de nós excluidos
{
    int cont = 0;
    if (primeiro != NULL)
    {
        No *no = primeiro, *aux = no->proximo, *anterior;
        while (aux != NULL)
        {
            if (no == primeiro)
            {
                if ((no->info % 2) == 0)
                {
                    primeiro = aux;
                    free(no);
                    no = primeiro;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
            else
            {
                if ((no->info % 2) == 0)
                {
                    anterior->proximo = aux;
                    free(no);
                    no = aux;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
        }
        //condição para o último nó
        if ((no->info % 2) == 0)
        {
            if (tamanho() > 1)
            {
                anterior->proximo = NULL;
                free(no);
            }
            else
            {
                free(no);
                primeiro = NULL;
            }
        }
    }
    return cont;
}
