import java.time.LocalDate;

public class Cliente extends Pessoa{
    private String escolaridade;
    private Agencia agencia;
    private Conta[] contas = new Conta[10]; // um cliente pode ter até 10 contas

    public Cliente(String nome, String cpf) {
        super(nome, cpf);
    }

    public Cliente (){
        super();
    }

    public Cliente(String cpf, String nome, String endereco, String estadoCivil, String escolaridade, LocalDate dataNascimento, Agencia agencia) {
        super(cpf, nome, endereco, estadoCivil, dataNascimento);
        this.escolaridade = escolaridade;
            this.agencia = agencia;
    }

    public String getEscolaridade() { return escolaridade; }
    public Agencia getAgencia() { return agencia; }

    public void setEscolaridade(String escolaridade) { this.escolaridade = escolaridade; }
    public void setAgencia(Agencia agencia) { this.agencia = agencia; }


}

