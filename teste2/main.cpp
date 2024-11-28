#include <iostream>
#include <mysql.h>

using namespace std;

// Função para criar um novo cliente
void createCliente(MYSQL* conn) {
    string cpf, nome, numero;
    cout << "\n=== CREATE Cliente ===\n";
    cout << "Digite o CPF: ";
    cin >> cpf;
    cout << "Digite o Nome: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, nome); // Lê uma string com espaços
    cout << "Digite o Número: ";
    cin >> numero;

    string query = "INSERT INTO Cliente (cpf, nome, numero) VALUES ('" + cpf + "', '" + nome + "', '" + numero + "')";
    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao inserir cliente: " << mysql_error(conn) << endl;
    } else {
        cout << "Cliente inserido com sucesso!" << endl;
    }
}

// Função para listar todos os clientes
void readClientes(MYSQL* conn) {
    cout << "\n=== READ Clientes ===\n";
    if (mysql_query(conn, "SELECT * FROM Cliente")) {
        cout << "Erro ao buscar clientes: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (result == NULL) {
        cout << "Erro ao armazenar resultado: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_ROW row;
    cout << "ID\tCPF\t\tNome\t\tNúmero" << endl;
    cout << "----------------------------------------------------" << endl;
    while ((row = mysql_fetch_row(result))) {
        cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << endl;
    }

    mysql_free_result(result);
}

// Função para atualizar um cliente
void updateCliente(MYSQL* conn) {
    int id;
    string nome, numero;
    cout << "\n=== UPDATE Cliente ===\n";
    cout << "Digite o ID do cliente que deseja atualizar: ";
    cin >> id;
    cout << "Digite o novo Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o novo Número: ";
    cin >> numero;

    string query = "UPDATE Cliente SET nome = '" + nome + "', numero = '" + numero + "' WHERE id = " + to_string(id);
    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao atualizar cliente: " << mysql_error(conn) << endl;
    } else {
        cout << "Cliente atualizado com sucesso!" << endl;
    }
}

// Função para deletar um cliente
void deleteCliente(MYSQL* conn) {
    int id;
    cout << "\n=== DELETE Cliente ===\n";
    cout << "Digite o ID do cliente que deseja deletar: ";
    cin >> id;

    string query = "DELETE FROM Cliente WHERE id = " + to_string(id);
    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao deletar cliente: " << mysql_error(conn) << endl;
    } else {
        cout << "Cliente deletado com sucesso!" << endl;
    }
}

// Função para criar um novo corretor
void createCorretor(MYSQL* conn) {
    string cpf, nome, numero;
    float salario;  // Novo atributo salario

    cout << "\n=== CREATE Corretor ===\n";
    cout << "Digite o CPF: ";
    cin >> cpf;
    cout << "Digite o Nome: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, nome);
    cout << "Digite o Telefone: ";
    cin >> numero;
    cout << "Digite o Salário: ";
    cin >> salario;  // Recebe o valor do salário

    // Atualiza a query SQL para incluir o campo salario
    string query = "INSERT INTO Corretor (cpf, nome, numero, salario) VALUES ('" + cpf + "', '" + nome + "', '" + numero + "', " + to_string(salario) + ")";

    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao inserir corretor: " << mysql_error(conn) << endl;
    } else {
        cout << "Corretor inserido com sucesso!" << endl;
    }
}

// Função para listar todos os corretores
void readCorretores(MYSQL* conn) {
    cout << "\n=== READ Corretores ===\n";
    if (mysql_query(conn, "SELECT * FROM Corretor")) {
        cout << "Erro ao buscar corretores: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (result == NULL) {
        cout << "Erro ao armazenar resultado: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_ROW row;
    cout << "ID\tCPF\t\tNome\t\tTelefone\tSalario" << endl;
    cout << "----------------------------------------------------" << endl;
    while ((row = mysql_fetch_row(result))) {
        cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << "\t" << row[4] << endl;
    }

    mysql_free_result(result);
}

// Função para atualizar um corretor
void updateCorretor(MYSQL* conn) {
    int id;
    string cpf, nome, numero;
    float salario;  // Novo atributo salario

    cout << "\n=== UPDATE Corretor ===\n";
    cout << "Digite o ID do corretor que deseja atualizar: ";
    cin >> id;
    cout << "Digite o novo CPF: ";
    cin >> cpf;
    cout << "Digite o novo Nome: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, nome);
    cout << "Digite o novo Telefone: ";
    cin >> numero;
    cout << "Digite o novo Salário: ";
    cin >> salario;  // Recebe o novo valor do salário

    // Atualiza a query SQL para incluir o campo salario
    string query = "UPDATE Corretor SET cpf = '" + cpf + "', nome = '" + nome + "', numero = '" + numero + "', salario = " + to_string(salario) + " WHERE id = " + to_string(id);

    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao atualizar corretor: " << mysql_error(conn) << endl;
    } else {
        cout << "Corretor atualizado com sucesso!" << endl;
    }
}

// Função para deletar um corretor
void deleteCorretor(MYSQL* conn) {
    int id;
    cout << "\n=== DELETE Corretor ===\n";
    cout << "Digite o ID do corretor que deseja deletar: ";
    cin >> id;

    string query = "DELETE FROM Corretor WHERE id = " + to_string(id);
    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao deletar corretor: " << mysql_error(conn) << endl;
    } else {
        cout << "Corretor deletado com sucesso!" << endl;
    }
}

// Função para criar uma nova propriedade
void createPropriedade(MYSQL* conn) {
    string endereco, tipo;
    float tamanho;  // Novo atributo tamanho

    cout << "\n=== CREATE Propriedade ===\n";
    cout << "Digite o Endereço: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, endereco);
    cout << "Digite o Tipo: ";
    cin >> tipo;
    cout << "Digite o Tamanho (em metros quadrados): ";
    cin >> tamanho;  // Recebe o valor do tamanho da propriedade

    // Atualiza a query SQL para incluir o campo tamanho
    string query = "INSERT INTO Propriedade (endereco, tipo, tamanho) VALUES ('" + endereco + "', '" + tipo + "', " + to_string(tamanho) + ")";

    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao inserir propriedade: " << mysql_error(conn) << endl;
    } else {
        cout << "Propriedade inserida com sucesso!" << endl;
    }
}

// Função para listar todas as propriedades
void readPropriedades(MYSQL* conn) {
    cout << "\n=== READ Propriedades ===\n";
    if (mysql_query(conn, "SELECT * FROM Propriedade")) {
        cout << "Erro ao buscar propriedades: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (result == NULL) {
        cout << "Erro ao armazenar resultado: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_ROW row;
    cout << "ID\tEndereço\t\tTipo\t\tTamanho" << endl;
    cout << "------------------------------------------------------------" << endl;
    while ((row = mysql_fetch_row(result))) {
        cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << endl;  // Exibe o campo tamanho
    }

    mysql_free_result(result);
}

// Função para atualizar uma propriedade
void updatePropriedade(MYSQL* conn) {
    int id;
    string endereco, tipo;
    float tamanho;  // Novo atributo tamanho

    cout << "\n=== UPDATE Propriedade ===\n";
    cout << "Digite o ID da propriedade que deseja atualizar: ";
    cin >> id;
    cout << "Digite o novo Endereço: ";
    cin.ignore();
    getline(cin, endereco);
    cout << "Digite o novo Tipo: ";
    cin >> tipo;
    cout << "Digite o novo Tamanho (em metros quadrados): ";
    cin >> tamanho;  // Recebe o novo valor do tamanho

    // Atualiza a query SQL para incluir o campo tamanho
    string query = "UPDATE Propriedade SET endereco = '" + endereco + "', tipo = '" + tipo + "', tamanho = " + to_string(tamanho) + " WHERE id = " + to_string(id);

    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao atualizar propriedade: " << mysql_error(conn) << endl;
    } else {
        cout << "Propriedade atualizada com sucesso!" << endl;
    }
}

// Função para deletar uma propriedade
void deletePropriedade(MYSQL* conn) {
    int id;
    cout << "\n=== DELETE Propriedade ===\n";
    cout << "Digite o ID da propriedade que deseja deletar: ";
    cin >> id;

    string query = "DELETE FROM Propriedade WHERE id = " + to_string(id);
    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao deletar propriedade: " << mysql_error(conn) << endl;
    } else {
        cout << "Propriedade deletada com sucesso!" << endl;
    }
}

// Função para criar um novo contrato
// Função para criar um novo contrato
void createContrato(MYSQL* conn) {
    int id_comprador, id_propriedade, id_corretor, id_vendedor;  // Atributos
    float valor;  // Novo atributo valor
    cout << "\n=== CREATE Contrato ===\n";
    cout << "Digite o ID do Comprador: ";
    cin >> id_comprador;
    cout << "Digite o ID da Propriedade: ";
    cin >> id_propriedade;
    cout << "Digite o ID do Corretor: ";
    cin >> id_corretor;
    cout << "Digite o ID do Vendedor: ";  // Solicita o id_vendedor
    cin >> id_vendedor;  // Recebe o ID do vendedor
    cout << "Digite o Valor do Contrato: ";  // Solicita o valor
    cin >> valor;  // Recebe o valor do contrato

    // Atualiza a query SQL para incluir o campo valor
    string query = "INSERT INTO Contrato (id_comprador, id_propriedade, id_corretor, id_vendedor, valor) VALUES ("
                   + to_string(id_comprador) + ", "
                   + to_string(id_propriedade) + ", "
                   + to_string(id_corretor) + ", "
                   + to_string(id_vendedor) + ", "
                   + to_string(valor) + ")";

    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao inserir contrato: " << mysql_error(conn) << endl;
    } else {
        cout << "Contrato inserido com sucesso!" << endl;
    }
}

// Função para listar todos os contratos
void readContratos(MYSQL* conn) {
    cout << "\n=== READ Contratos ===\n";

    // Consulta para garantir que estamos pegando todos os campos
    if (mysql_query(conn, "SELECT id, id_comprador, id_propriedade, id_corretor, id_vendedor, valor FROM Contrato")) {
        cout << "Erro ao buscar contratos: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (result == NULL) {
        cout << "Erro ao armazenar resultado: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_ROW row;
    cout << "ID\tID Comprador\tID Propriedade\tID Corretor\tID Vendedor\tValor" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    while ((row = mysql_fetch_row(result))) {
        // Exibe todos os campos, incluindo o campo valor
        cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << "\t" << row[4] << "\t" << row[5] << endl;
    }

    mysql_free_result(result);
}


// Função para atualizar um contrato
void updateContrato(MYSQL* conn) {
    int id, id_comprador, id_propriedade, id_corretor, id_vendedor;  // Atributos
    float valor;  // Novo atributo valor
    cout << "\n=== UPDATE Contrato ===\n";
    cout << "Digite o ID do contrato que deseja atualizar: ";
    cin >> id;
    cout << "Digite o novo ID do Comprador: ";
    cin >> id_comprador;
    cout << "Digite o novo ID da Propriedade: ";
    cin >> id_propriedade;
    cout << "Digite o novo ID do Corretor: ";
    cin >> id_corretor;
    cout << "Digite o novo ID do Vendedor: ";  // Solicita o novo id_vendedor
    cin >> id_vendedor;  // Recebe o novo ID do vendedor
    cout << "Digite o novo Valor do Contrato: ";  // Solicita o novo valor
    cin >> valor;  // Recebe o novo valor

    // Atualiza a query SQL para incluir o campo valor
    string query = "UPDATE Contrato SET id_comprador = " + to_string(id_comprador)
                   + ", id_propriedade = " + to_string(id_propriedade)
                   + ", id_corretor = " + to_string(id_corretor)
                   + ", id_vendedor = " + to_string(id_vendedor)
                   + ", valor = " + to_string(valor)
                   + " WHERE id = " + to_string(id);

    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao atualizar contrato: " << mysql_error(conn) << endl;
    } else {
        cout << "Contrato atualizado com sucesso!" << endl;
    }
}

// Função para deletar um contrato
void deleteContrato(MYSQL* conn) {
    int id;
    cout << "\n=== DELETE Contrato ===\n";
    cout << "Digite o ID do contrato que deseja deletar: ";
    cin >> id;

    string query = "DELETE FROM Contrato WHERE id = " + to_string(id);
    if (mysql_query(conn, query.c_str())) {
        cout << "Erro ao deletar contrato: " << mysql_error(conn) << endl;
    } else {
        cout << "Contrato deletado com sucesso!" << endl;
    }
}

int main() {
    // Inicializa o MySQL
    MYSQL* connect = mysql_init(NULL);
    if (!connect) {
        cout << "Erro ao iniciar MySQL" << endl;
        return 1;
    }

    // Conecta ao banco de dados
    connect = mysql_real_connect(connect, "127.0.0.1", "root", "senha", "Imobiliaria", 3306, NULL, 0);
    if (!connect) {
        cout << "Erro ao conectar ao banco de dados: " << mysql_error(connect) << endl;
        return 1;
    }
    cout << "Conexão com o banco de dados estabelecida!" << endl;

    // Menu interativo para CRUD
    int opcao;
    int opcao2;
    do {
        cout << "\n=== Menu CRUD ===\n";
        cout << "1. CRUD Cliente\n";
        cout << "2. CRUD Corretor\n";
        cout << "3. CRUD Propriedade\n";
        cout << "4. CRUD Contrato\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                do {
                    cout << "\n=== Menu CRUD Cliente ===\n";
                    cout << "1. Create\n";
                    cout << "2. Read\n";
                    cout << "3. Update\n";
                    cout << "4. Delete\n";
                    cout << "5. Sair\n";
                    cout << "Escolha uma opcao: ";
                    cin >> opcao2;

                    switch (opcao2) {
                        case 1:
                            createCliente(connect);
                            break;
                        case 2:
                            readClientes(connect);
                            break;
                        case 3:
                            updateCliente(connect);
                            break;
                        case 4:
                            deleteCliente(connect);
                            break;
                        case 5:
                            cout << "Saindo..." << endl;
                            break;
                        default:
                            cout << "Opção inválida. Tente novamente." << endl;
                    }
                } while (opcao2 != 5);
                break;
            case 2:
                do {
                    cout << "\n=== Menu CRUD Corretor ===\n";
                    cout << "1. Create\n";
                    cout << "2. Read\n";
                    cout << "3. Update\n";
                    cout << "4. Delete\n";
                    cout << "5. Sair\n";
                    cout << "Escolha uma opcao: ";
                    cin >> opcao2;

                    switch (opcao2) {
                        case 1:
                            createCorretor(connect);
                            break;
                        case 2:
                            readCorretores(connect);
                            break;
                        case 3:
                            updateCorretor(connect);
                            break;
                        case 4:
                            deleteCorretor(connect);
                            break;
                        case 5:
                            cout << "Saindo..." << endl;
                            break;
                        default:
                            cout << "Opção inválida. Tente novamente." << endl;
                    }
                } while (opcao2 != 5);
                break;
            case 3:
                do {
                    cout << "\n=== Menu CRUD Propriedade ===\n";
                    cout << "1. Create\n";
                    cout << "2. Read\n";
                    cout << "3. Update\n";
                    cout << "4. Delete\n";
                    cout << "5. Sair\n";
                    cout << "Escolha uma opcao: ";
                    cin >> opcao2;

                    switch (opcao2) {
                        case 1:
                            createPropriedade(connect);
                            break;
                        case 2:
                            readPropriedades(connect);
                            break;
                        case 3:
                            updatePropriedade(connect);
                            break;
                        case 4:
                            deletePropriedade(connect);
                            break;
                        case 5:
                            cout << "Saindo..." << endl;
                            break;
                        default:
                            cout << "Opção inválida. Tente novamente." << endl;
                    }
                } while (opcao2 != 5);
                break;
            case 4:
                do {
                    cout << "\n=== Menu CRUD Contrato ===\n";
                    cout << "1. Create\n";
                    cout << "2. Read\n";
                    cout << "3. Update\n";
                    cout << "4. Delete\n";
                    cout << "5. Sair\n";
                    cout << "Escolha uma opcao: ";
                    cin >> opcao2;

                    switch (opcao2) {
                        case 1:
                            createContrato(connect);
                            break;
                        case 2:
                            readContratos(connect);
                            break;
                        case 3:
                            updateContrato(connect);
                            break;
                        case 4:
                            deleteContrato(connect);
                            break;
                        case 5:
                            cout << "Saindo..." << endl;
                            break;
                        default:
                            cout << "Opção inválida. Tente novamente." << endl;
                    }
                } while (opcao2 != 5);
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 5);

    // Fecha a conexão
    mysql_close(connect);
    return 0;
}
