# MultiThread-ContaPrimosMatriz
Dada uma matriz de números naturais aleatórios verificar quantos números primos existem e contabilizar o tempo necessário para realizar esta computação. Veja na íntegra o [contexto de implementação](./contexto.pdf) do referido programa.

# Compilação

> :bowtie: Foi usado o compilador de C++ *Clang version 7.0.0.3~Ubuntu0.18.04.1*. Pode-se também usar o compilador g++ para gerar o arquivo executável na sua máquina.

> :warning:	Atenção! O código-fonte desse repositório deve funcionar em sistemas operacionais baseados em UNIX, como as distribuições do Linux. Sistemas baseados no DOS, como o Windows, assim como o MacOS e vários outros sistemas operacionais não estão necessariamente contemplados nessa categoria.

## TaskList
### Implementar Execução Serialmente
- [X] Adicionar Bibliotecas do Sistema/ de C/C++ que serão utilizadas
- [X] Macros para parametrização do programa
- [X] Identicar se um número é primo
- [X] Matriz de inteiros positivos com valores aleatórios
 
### Implementar Execução por Threads
- [X] Particionar Matriz em Blocos
- [X] Parametrizar Threads
- [X] Implementar Rotina
- [X] Definir qnt. de Threads e atuação de cada uma (vide parâmetros)
- [ ] Medir tempo de processador serial
- [ ] Medir tempo de processador para as threads


### Links
Acesse o mesmo repositório no:
* :bowtie: [Repl.it](https://repl.it/@JackJonas/MultiThread-ContaPrimosMatriz).
* :octocat: [GitHub](https://github.com/Jakiminski/MultiThread-ContaPrimosMatriz/)

[GNU GProf](https://www.ibm.com/developerworks/br/local/linux/gprof_introduction/index.html)
