# -*- coding: cp1252 -*-

import os
import re
import sys

encoding = 'iso-8859-1'


# Funcao que retorna uma lista com subdiretorios e arquivos
def lista_caminho(caminho):
    lista_diretorio = []
    for caminho, _, arquivos in os.walk(caminho):
        lista_diretorio.append((caminho, arquivos))
    return lista_diretorio


#Funcao que escreve o arquivo.sar contendo a especificacao do diretorio
'''
Caminho do diretorio
Nemero de arquivos
Nome do arquivo
Tamanho do arquivo
Arquivo
'''
def escrever(caminho):
    lista_diretorio = lista_caminho(caminho)

#Separa apenas o nome do diretório e sua posição
    expressao_caminho_base = re.split(r'\\|/', caminho)
    posicao_caminho_base = len(expressao_caminho_base)-1

#Abre arquivo
    with open('arquivo.sar', 'wb') as arquivo_escrita:
        for caminho, arquivos in lista_diretorio:

            #Separa o caminho a partir do nome do diretorio base
            expressao_caminho = [e + '/' for e in re.split(r'\\|/', caminho) if not e == '']
            string_caminho = ''.join(expressao_caminho[posicao_caminho_base - 1:])[:-1]

            #Escreve arquivo
            arquivo_escrita.write(bytes(string_caminho + '\n', encoding))
            arquivo_escrita.write(bytes(str(len(arquivos)) + '\n', encoding))
            for f in arquivos:
                with open(caminho + '/' + f, 'rb') as arquivo:
                    dados = arquivo.read()
                arquivo_escrita.write(bytes(f + '\n', encoding))
                arquivo_escrita.write(bytes(str(len(dados)) + '\n', encoding))
                arquivo_escrita.write(dados)
                arquivo_escrita.write(bytes('\n', encoding))
    return


# Funcao que imprime o diretorio, subdiretorios e arquivos
def listar(caminho):
    with open(caminho, 'rb') as arquivo:
        while True:

            #Imprime nome do diretorio e verifica se chegou ao final do arquivo
            nome_diretorio = arquivo.readline().decode(encoding)[:-1]
            if nome_diretorio == '':
                break
            print('/' + nome_diretorio)

            #Itera sobre o nemero de arquivos no diretorio
            n_arquivos = int(arquivo.readline().decode(encoding))

            for i in range(n_arquivos):
                print('\t' + arquivo.readline().decode(encoding)[:-1])
                tamanho = int(arquivo.readline().decode(encoding))
                print('\t\t' + arquivo.read(tamanho+1).decode(encoding, errors='replace')[:-1])
    return


def extrair(caminho):
    with open(caminho, 'rb') as arquivo:
        while True:

            # Cria diretorio e verifica se chegou ao final do arquivo
            nome_diretorio = arquivo.readline().decode(encoding)[:-1]
            if nome_diretorio == '':
                break
            os.makedirs(nome_diretorio)

            #Itera sobre o numero de arquivos no diretorio
            n_arquivos = int(arquivo.readline().decode(encoding))

            for i in range(n_arquivos):
                nome_arquivo = arquivo.readline().decode(encoding)[:-1]
                with open(nome_diretorio + '/' + nome_arquivo, 'wb') as arquivo_escrita:
                    tamanho = int(arquivo.readline().decode(encoding))
                    conteudo = arquivo.read(tamanho + 1)
                    arquivo_escrita.write(conteudo)
    return


def main(argv):
    if len(argv) != 3:
        print('Formato de entrada:')
        print('sar -c diretorio')
        print('sar [-e|-l] arquivo_sar')
        exit()
    if argv[1] == '-c':
        print('Cria arquivo do diretorio\n')
        escrever(argv[2])
    elif argv[1] == '-e':
        print('Extrai arquivo\n')
        extrair(argv[2])
    elif argv[1] == '-l':
        print('Lista arquivo\n')
        listar(argv[2])


    else:
        print(u'Argumento inválido')
    pass


if __name__ == "__main__":
    main(sys.argv)
