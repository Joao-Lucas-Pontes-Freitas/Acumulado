import java.io.Serializable;

public class Agencia implements Serializable {
    private int numero;
    private String nome;
    private String endereco;
    private String cidade;
    private String estado;
    private String bairro;
    private Gerente gerente;

    public Agencia(int numero, String nome, String endereco, String cidade, String estado, String bairro, Gerente gerente) {
        this.numero = numero;
        this.nome = nome;
        this.endereco = endereco;
        this.cidade = cidade;
        this.estado = estado;
        this.bairro = bairro;
        if(gerente == null)
            throw new GerenteNuloException("Gerente não pode ser nulo");
        this.gerente = gerente;
    }

    public int getNumero() { return numero; }
    public String getNomeFicticio() { return nome; }
    public String getEndereco() { return endereco; }
    public String getCidade() { return cidade; }
    public String getEstado() { return estado; }
    public String getBairro() { return bairro; }
    public Gerente getGerente() { return gerente; }


    public void setNumero(int numero) {
        this.numero = numero;
    }
    public void setNomeFicticio(String nome) {
        this.nome = nome;
    }
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    public void setCidade(String cidade) {
        this.cidade = cidade;
    }
    public void setEstado(String estado) {
        this.estado = estado;
    }
    public void setBairro(String bairro) {
        this.bairro = bairro;
    }
    public void setGerente(Gerente gerente) {
        this.gerente = gerente;
    }

    public void imprimeDadosAgencia() {
        System.out.println("Dados da agência:");
        System.out.println(" - Nome: " + nome);
        System.out.println(" - Endereço: " + endereco);
        System.out.println(" - Cidade: " + cidade);
        System.out.println(" - Estado: " + estado);
        System.out.println(" - Bairro: " + bairro);
        System.out.println(" - Gerente da agência: " + gerente.getNome());
    }
}
