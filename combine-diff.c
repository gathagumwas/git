#include "object-store.h"
				    struct lline *newline, int lennew,
	if (newline == NULL)
		return newline;
		for (j = 1, newend = newline; j < lennew + 1; j++) {
				newline = lline->next;
	newend = newline;
static char *grab_blob(struct repository *r,
		       const struct object_id *oid, unsigned int mode,
		*size = fill_textconv(r, textconv, df, &blob);
		blob = read_object_file(oid, &type, size);
static void consume_hunk(void *state_,
			 long ob, long on,
			 long nb, long nn,
			 const char *funcline, long funclen)

	state->ob = ob;
	state->on = on;
	state->nb = nb;
	state->nn = nn;
	state->lno = state->nb;
	if (state->nn == 0) {
		/* @@ -X,Y +N,0 @@ removed Y lines
		 * that would have come *after* line N
		 * in the result.  Our lost buckets hang
		 * to the line after the removed lines,
		 *
		 * Note that this is correct even when N == 0,
		 * in which case the hunk removes the first
		 * line in the file.
		 */
		state->lost_bucket = &state->sline[state->nb];
		if (!state->nb)
			state->nb = 1;
	} else {
		state->lost_bucket = &state->sline[state->nb-1];
	if (!state->sline[state->nb-1].p_lno)
		state->sline[state->nb-1].p_lno =
			xcalloc(state->num_parent, sizeof(unsigned long));
	state->sline[state->nb-1].p_lno[state->n] = state->ob;
}

static void consume_line(void *state_, char *line, unsigned long len)
{
	struct combine_diff_state *state = state_;
static void combine_diff(struct repository *r,
			 const struct object_id *parent, unsigned int mode,
	parent_file.ptr = grab_blob(r, parent, mode, &sz, textconv, path);
	if (xdi_diff_outf(&parent_file, result_file, consume_hunk,
			  consume_line, &state, &xpp, &xecfg))
	int abbrev = opt->flags.full_index ? GIT_SHA1_HEXSZ : DEFAULT_ABBREV;
		abb = find_unique_abbrev(&elem->parent[i].oid,
	abb = find_unique_abbrev(&elem->oid, abbrev);
	userdiff = userdiff_find_by_path(opt->repo->index, elem->path);
	if (opt->flags.allow_textconv)
		result = grab_blob(opt->repo, &elem->oid, elem->mode, &result_size,
			if (resolve_gitlink_ref(elem->path, "HEAD", &oid) < 0)
				result = grab_blob(opt->repo, &elem->oid,
						   elem->mode, &result_size,
						   NULL, NULL);
				result = grab_blob(opt->repo, &oid, elem->mode,
			result_size = fill_textconv(opt->repo, textconv, df, &result);
				if (convert_to_git(rev->diffopt.repo->index,
						   elem->path, result, len, &buf, global_conv_flags_eol)) {
			buf = grab_blob(opt->repo,
					&elem->parent[i].oid,
			if (oideq(&elem->parent[i].oid,
				  &elem->parent[j].oid)) {
			combine_diff(opt->repo,
				     &elem->parent[i].oid,
	diffopts.flags.recursive = 1;
	diffopts.flags.allow_external = 0;
			opt->flags.follow_renames	||
			(opt->pickaxe_opts & DIFF_PICKAXE_KINDS_MASK)	||