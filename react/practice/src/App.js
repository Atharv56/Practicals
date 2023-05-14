import './styles.css'
import './App.css';
import SingleElement from './components/SingleElement';
import MultipleElements from './components/MultipleElements';
import UserDef from './components/UserDefined';
import Greeting from './components/Props';
import Counter from './components/IncreDecre';

function App() {
  return (
    <div className="my-app">
      <Greeting name="Atharv"/>
      <SingleElement/>
      <MultipleElements/>
      <h6>Reuse MultipleElements</h6>
      <MultipleElements/>
      <UserDef />
      <Counter />
    </div>
  );
}

export default App; 