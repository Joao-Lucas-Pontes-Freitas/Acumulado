import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        ContaCorrente contaCorrente = new ContaCorrente(123, 11323, 230, 230, 230);
        System.out.println(contaCorrente.getDataAbertura());
        Transacao transacao = new Transacao(contaCorrente, LocalDate.now(),contaCorrente.getSaldo(), "deposito");
//        Cliente cliente = new Cliente("12345678911", "José", "rua abacaxi", "solteirao", "superior", LocalDate.of(2004, 1, 12));
//        System.out.println(cliente.getDataNascimento());
        Funcionario funcionario = new Funcionario("12345678911", "José", "rua abacaxi", "solteirao", LocalDate.of(2004, 1, 6),
                1213, "10910491", "todo_dia", "gerente", 1000, LocalDate.of(2008, 6, 13));
        System.out.println(funcionario.getSalario());
    }
}
