# display-sonda
Display com display 7 segmentos para sonda wideband ODG 4.9 usando a placa MultiPic Advanced

# Especificação da entrada de sonda

Tensão | Lambda
-------|-------
0.2V | 0.59
4.8V | 1.30

Funções para conversão:

`Lambda = (0.15435 * V) + 0,55913` (Eq. 1)

`Lambda = ((0.77175 * (10bit ADC value)/1023) + 0,55913` (Eq. 2)

1023 = 5v
x = 0

# Lógica da aplicação:

1. Inicialização do PIC
2. Loop Principal

## Loop Principal

1. Efetua conversão do ADC
2. Utiliza a Eq. 2 para transformar o valor em lambda
3. Formata o resultado da conversão para "X.XX" dividindo em 3 variáveis
4. Multiplexa os dígitos individuais, com tempo de permanencia de `DIGIT_DURATION`


