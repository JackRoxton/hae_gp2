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
			auto _l = l;
			auto _r = r;
			if (!l) {
				delete this;
				return _r;
			} 
			else if (!r) {
				delete this;
				return _l;
			}
			else {
				delete this;
				l->merge(r);
				return l;
			}
		}
		else if (v < val) {
			if(l)
			l->remove(v);
		}
		else {
			if(r)
			r->remove(v);
		}
		return(this);
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
			if(l)
			l->search(v);
		}
		else {
			if(r)
			r->search(v);
		}
	}
};
