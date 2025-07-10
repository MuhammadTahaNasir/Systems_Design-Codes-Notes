# 🎮 Mario Game – Decorator Pattern in C++

## 💡 Overview

This document explains the **Decorator Pattern** with a Mario game example where Mario gains new abilities (like height, gun, and star power) at runtime. The design showcases dynamic behavior enhancement without changing the base class.

---

## 📐 UML Diagram – `Mario_UML.puml`

### Explanation:

- **`ICharacter`**: Interface with `getAbilities()` – defines the contract for all characters.
- **`MarioCharacter`**: Concrete component that returns `"Mario Character"`.
- **`CharacterDecorator`**: Abstract decorator that implements `ICharacter` and holds a reference to another `ICharacter`.
- **Concrete Decorators**:
  - `HeightDecorator`
  - `GunDecorator`
  - `StarDecorator`
  
Each concrete decorator enhances the character's abilities by appending new functionality to the base response via delegation.

### Relationships:

- **Inheritance** ensures compatibility with the base interface.
- **Composition** enables flexible delegation and wrapping.

---

## 🔄 Sequence Diagram – `Mario_Sequence.puml`

### Interaction Flow:

1. The player calls `getAbilities()` on a plain `MarioCharacter` → returns `"Mario Character"`.
2. Mario is wrapped in `HeightDecorator` → adds `" with Height"`.
3. Then wrapped in `GunDecorator` → adds `" with Gun"`.
4. Finally wrapped in `StarDecorator` → adds `" with Star (Limited Time)"`.

Each decorator wraps the previous one, forming a **chain of responsibilities**, adding new features dynamically.

---

## 🚀 Implementation Goals

We implement the pattern in two contexts:

### 1. **Mario Game:**
Mario dynamically gains powers like height, gun, and a star boost during gameplay.

### 2. **(Optional Extension)** AI Pipeline:
The same decorator concept can be used to stack text-processing features in an AI pipeline (e.g., tokenization → stemming → stopword removal).

---

## 🧪 Output

```text
Base Character: Mario Character  
After Height Power-Up: Mario Character with Height  
After Gun Power-Up: Mario Character with Height with Gun  
After Star Power-Up: Mario Character with Height with Gun with Star (Limited Time)
