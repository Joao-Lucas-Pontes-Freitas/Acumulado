class DPDA:
    def __init__(self, states, input_symbols, stack_symbols, transitions, initial_state, initial_stack_symbol, final_states):
        self.states = states
        self.input_symbols = input_symbols
        self.stack_symbols = stack_symbols
        self.transitions = transitions
        self.current_state = initial_state
        self.current_stack = [initial_stack_symbol]
        self.final_states = final_states

    def is_deterministic(self):
        for state, transitions in self.transitions.items():
            for symbol, stack_action in transitions.items():
                if len(stack_action) != 2:
                    return False  # Non-deterministic if the transition doesn't have exactly two elements
                next_state, stack_push = stack_action
                if (state, symbol) in [(s, a) for s, a in self.transitions.values()]:
                    return False  # Non-deterministic if there are multiple transitions for the same state and symbol
        return True

# Exemplo de um DPDA determinístico
dpda = DPDA(
    states={'q0', 'q1'},
    input_symbols={'0', '1'},
    stack_symbols={'X', 'Y'},
    transitions={
        'q0': {
            '0': ('q0', ['X']),
            '1': ('q1', ['Y'])
        },
        'q1': {
            '1': ('q1', []),
            '0': ('q0', [])
        }
    },
    initial_state='q0',
    initial_stack_symbol='Z',
    final_states={'q1'}
)

# Verificar se é determinístico
print("O DPDA é determinístico:", dpda.is_deterministic())
