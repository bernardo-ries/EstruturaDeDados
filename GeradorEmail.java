import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.stream.Collectors;

public class GeradorEmail {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<String, String> emails = new HashMap<>();

        while (true) {
            System.out.println("Digite o nome completo (ou 'sair' para finalizar):");
            String nomeCompleto = scanner.nextLine().trim();

            if (nomeCompleto.equalsIgnoreCase("sair")) {
                break;
            }

            String[] partes = nomeCompleto.split(" ");
            if (partes.length < 2) {
                System.out.println("Erro: Digite pelo menos um nome e um sobrenome.");
                continue;
            }

            String primeiroNome = partes[0].toLowerCase();
            String ultimoNome = partes[partes.length - 1].toLowerCase();
            String email = primeiroNome + "." + ultimoNome + "@ufn.edu.br";

            if (emails.containsKey(email)) {
                System.out.println("Erro: Email já cadastrado.");
                continue;
            }

            emails.put(email, nomeCompleto);
        }

        System.out.println("\nLista de emails cadastrados:");
        emails.entrySet().stream()
                .sorted(Map.Entry.comparingByValue())
                .forEach(entry -> System.out.println(entry.getValue() + " -> " + entry.getKey()));
    }
}
