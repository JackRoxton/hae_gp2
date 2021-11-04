#pragma once

template<typename Value>

class Tree {
public:
	Value val = {};
	Tree* l = nullptr;
	Tree* r = nullptr;

	Tree(Value v) {
		val = v;
	}

	Tree* insert(Value v) {
		if (v < val) {
			if (l == nullptr) {
				l = new Tree(v);
			}
			else {
			l->insert(v);
			}
		}
		else {
			if (r == nullptr) {
				r = new Tree(v);
			}
			else {
			r->insert(v);
			}
		}
		return this;
	}

	Tree* remove(Value v) {
		if (v == val) {
			Tree* _l = l;
			Tree* _r = r;
			if (!l) {
				delete this;
				return _r;
			} 
			else if (!r) {
				delete this;
				return _l;
			}
			else {
				l->merge(r);
				delete this;
				return l;
			}
		}
		else {
			if (v < val) {
				if (l)
					l = l->remove(o);
			}
			else {
				if (r)
					r = r->remove(o);
			}
			return this;
		}
	}

	Tree* merge(Tree* a) {
		Value vo = a->val;
		insert(vo);
		if (other->l)merge(other->l);
		if (other->r)merge(other->r);
		delete a;
		return this;
	}

	Tree* search(Value v) {
		if (v == val) {
			return this;
		}
		if (v < val) {
			if (l)
				return l->search(v);
			else
				return nullptr;
		}
		else {
			if(r)
				return r->search(v);
			else
				return nullptr;
		}
	}
};
