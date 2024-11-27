-- Criação do banco de dados
CREATE DATABASE Imobiliaria;
USE Imobiliaria;
DROP DATABASE imobiliaria;

-- Tabela Cliente
CREATE TABLE Cliente (
    id INTEGER PRIMARY KEY auto_increment,
    cpf VARCHAR(11) UNIQUE NOT NULL,
    nome VARCHAR(50) NOT NULL,
    numero VARCHAR(11)
);

-- Tabela Propriedade
CREATE TABLE Propriedade (
    id INTEGER PRIMARY KEY auto_increment,
    tipo VARCHAR(50),
    tamanho FLOAT(20) NOT NULL
);

-- Tabela Endereco
CREATE TABLE Endereco (
    id INTEGER PRIMARY KEY auto_increment,
    id_propriedade INTEGER NOT NULL,
    numero VARCHAR(10),
    rua VARCHAR(50),
    bairro VARCHAR(50),
    cidade VARCHAR(50),
    estado VARCHAR(50),
    FOREIGN KEY (id_propriedade) REFERENCES Propriedade(id)
);

-- Tabela Corretor
CREATE TABLE Corretor (
    id INTEGER PRIMARY KEY auto_increment,
    cpf VARCHAR(11) UNIQUE NOT NULL,
    nome VARCHAR(50) NOT NULL,
    numero VARCHAR(11),
    salario FLOAT(20) NOT NULL
);

-- Tabela Contrato
CREATE TABLE Contrato (
    id INTEGER PRIMARY KEY auto_increment,
    id_propriedade INTEGER NOT NULL,
    id_corretor INTEGER NOT NULL,
    id_vendedor INTEGER NOT NULL,
    id_comprador INTEGER NOT NULL,
    tipo VARCHAR(50),
    valor FLOAT(20) NOT NULL,
    FOREIGN KEY (id_propriedade) REFERENCES Propriedade(id),
    FOREIGN KEY (id_vendedor) REFERENCES Cliente(id),
    FOREIGN KEY (id_comprador) REFERENCES Cliente(id),
    FOREIGN KEY (id_corretor) REFERENCES Corretor(id)
);


