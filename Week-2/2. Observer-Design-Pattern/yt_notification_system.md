# 📘 YouTube Notification System

**Design Pattern:** Observer Pattern  
**Language:** C++

---

## 🧠 Concept

Let’s implement the **Observer Pattern** for a YouTube-like system where:

- **Channel (Subject)** notifies all **Subscribers (Observers)** when a new video is uploaded.
- This pattern helps in **loose coupling** between the channel and its subscribers.

---

## 📦 Example

YouTube Notification System using the Observer Pattern in C++.

---

## 🔎 Explanation

### `ConcreteObservable (TechBit)`
Represents the YouTube channel that maintains a list of observers (subscribers). When a new video is uploaded, all observers are notified.

### `ConcreteObserver (Ali, Sana)`
Subscribers who receive notifications and fetch the latest video title.

### Notification Flow

1. `Ali` and `Sana` subscribe to `TechBit`.
2. On the first upload, both get notified.
3. `Ali` unsubscribes.
4. On the second upload, only `Sana` is notified.

---

## 🛠 Implementation Details

### ✅ Subscription Management

- Uses a dynamic data structure (e.g., `vector<IObserver*>`) to store subscribers.
- `add()` method prevents duplicate subscriptions.
- `remove()` method allows clean unsubscription using `std::remove`.

### ✅ Notification Mechanism

- `notify()` method loops through all observers and calls their `update()` method.
- Each observer uses `getState()` to get the latest video info.

### ✅ State Management

- Channel state is maintained (e.g., latest video title).
- Updated using `setState()` method.
- Observers access the state only when notified.

### ✅ Loose Coupling

- Uses interfaces (`IObserver`, `IObservable`) to abstract implementation.
- Allows adding/removing observers without changing subject logic.

---

## 🧩 Design Pattern Benefit

> The Observer Pattern helps **decouple the subject from its observers**, providing flexibility and scalability in systems where multiple objects need to react to state changes.
